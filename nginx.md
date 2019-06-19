# Nginx

## configuration
1. http
1. server
1. upstream
1. location

## start
```
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
