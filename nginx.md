# Nginx

## configuration
1. http
1. server
1. upstream
1. location

## start

```sh
./nginx

# hot delploy
cp -r /compiling_dir/objs/nginx /installed_ngins/sbin/ -f
kill -USR2 running_nginx_pid
kill -WINCH old_nignx_pid  # close old worker process gentel
# old master process are alive for easy rollback (using reload command)

# change config
./nginx -s reload

# split log
mv old.log bak_dir/
./nginx  -s reopen
# log splite can be done via crontab

```

## static resources service
```
log_format format_name '$remove_addr - $remote_user [$time_local] "$request" '
'$status $body_bytes_sent "$http_referer"'
'"$http_user_agent" "$http_x_forwarded_for"';

gzip on;	# turn gzip
# gzip_min_length	gzip_types	gzip_comp_levels

location / {
	alias mydir/; 	# static resource dir

	autoindex on;		# files can be accessed vir http://ser:port/dir/filename
	#set $limit_rate 1k; 	# return speed, e.g. control bandwith of big files return to make chances for small files return

	access_log  logs/my.server.access.log  format_name; # name defined above
}
```

## anti proxy

* business server
```
server { 
    listen ip:8080;
}
# restart nginx - not reload since port change
```

* proxy server with cache
```
upstream local {
	127.0.0.1:8080; #ip:port configed in each server's nginx.conf
}

proxy_cache_path /tmp/nginxcache levels=1:2 keys_zone=my_cache:10m max_size=1g inactive=60m use_temp_path=off;

location {
	proxy_pass http://local;

	# let business server get info from client (not proxy)
	proxy_set_header Host $host;
	proxy_set_header X-Real_IP $remote_addr;

	# proxy_cache
	proxy_cache my_cache; 		# my_cache is the keys_zone configed previous
	proxy_cache_key $host$uri$is_args$args;
	proxy_cache_valid 200 304 302 1d;	# codes not return
}
```


## goAccess

# TODO

## SSL TLS

<img src="img/ssl_tls.png" />

* certificate
  * DV - domain validated
  * OV - origanization validated
  * EV - extended validation

* nginx server sends two certificates to browser/client
  * server cert
  * second level cert
  * root CA is not sent since it is contained by browser/OS

* CSR - request certificate issuance
* performance improvement
  * for small files - asymmetric algo e.g. `ECDHE`
  * big files - e.g. `ACE`

* steps
  1. client hello
    * supported ciphers
    * random number
    * session id
  1. server hello
    * choosen ciphers
    * random num
    * session id (re-use or new)
  1. server cert
  1. server hello
    * done
  1. clientkey exchange message (C -> S)
    * encrypted premaster secret
  1. key generation (client and server)
  1. cipherSpec exchange / finished (C -> S)
  1. cipherSpec exchange / finished (S -> C)


* config
```
yum install python2-certrot-nginx
certbot --nginx --nginx-server-root=/usr/local/nginx/conf -d my.server.org
```

## Lua in OpenResty
```
location {
	default_type text/html;
	content_by_lua 'ngx.say(ngx.req.get_headers()["User-Agent"])';
}
```

## Nginx Architecture
* multiple process
  * worker processes have the same num with num of cpu kernel
    * high performance - use all cpu kernels
    * high availibility
    * when using multiple threads, one crash thread may make the process stop
  * master - child communicate via signal
  * child processes communicate via shared memory???signal???

```
kill -SIGHUB master_pid 	# is same with
./nginx -s reload

# stop a child process, send CHLD signal to master, master process would open a new child
kill -SIGTERM child_pid
```

* signal and command
```
reload: HUB
quit:	QUIT
stop:	TERM // INT?
reopen:	USR1

# signals only available to master, and no corresponding command
USR2
WINCH
```

## Web tool

* wireshark


## epoll, poll, select

* poll & select
  * where there has ready event, kernel parse all event queue, including unready ones
* epoll
  * `rdr` - red-black tree stores all events/connections
  * `rdllink` - all ready connections/events

* performance
  * traditional app server 
    * multiple process/thread, it has interchange between them, it is slow for huge num of connections
  * nginx
    * single process, no interchange
    * javascript, openresty have sync & non-block functions

* Nginx Modules
  * <img src="img/nginx_modules.png" />

* `worker_connections` config
  * default is 512
  * each connections is `ngx_connection_s` (232 bytes) and read/write arrays `ngx_event_s` (96 bytes)
  * so, each connections is (232 + 96 * 2) bytes on 64bit system

* `ngx_connections.pool`
  * one connection cound have many request (one connection with multiple read), e.g. keep_alive option
  * `connection pool` - only allocate once when connection, reuse, it is small (default is `512` bytes)
  * `request pool` - alloc for every request, defualt is `4k`, because it has more big context content






