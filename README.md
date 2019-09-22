

<!-- MarkdownTOC autolink=true levels="1,2,3,4,5" -->

- [linux](#linux)
    - [check OS release version](#check-os-release-version)
    - [vim color scheme](#vim-color-scheme)
    - [crontab - scheduled task](#crontab---scheduled-task)
  - [Commands](#commands)
    - [`help`, `man`, `info`](#help-man-info)
      - [man](#man)
      - [help](#help)
      - [info](#info)
    - [screen](#screen)
    - [ps pstree top](#ps-pstree-top)
  - [User & Group](#user--group)
    - [User](#user)
    - [Group](#group)
    - [su, sudo](#su-sudo)
    - [file permission](#file-permission)
  - [Network Configuration](#network-configuration)
    - [net-tools](#net-tools)
      - [ifconfig](#ifconfig)
      - [mii-tool](#mii-tool)
      - [route](#route)
    - [iproute2](#iproute2)
  - [network trouble shooting](#network-trouble-shooting)
    - [ping](#ping)
    - [traceroute](#traceroute)
    - [mtr        - my traceroute, analysis data package](#mtr---my-traceroute-analysis-data-package)
    - [nslookup   - domain](#nslookup---domain)
    - [telnet     - host can access, but not service, check port](#telnet---host-can-access-but-not-service-check-port)
    - [tcpdump    -  all tcp packages](#tcpdump---all-tcp-packages)
    - [netstat    - service listen](#netstat---service-listen)
    - [ss](#ss)
  - [Network Service Management](#network-service-management)
  - [Liberay Management](#liberay-management)
    - [rpm](#rpm)
    - [deb](#deb)
  - [Package Management](#package-management)
    - [yum](#yum)
    - [apt](#apt)
  - [Kernel](#kernel)

<!-- /MarkdownTOC -->


# linux

### check OS release version
1. `cat /etc/*release`
1. `lsb_release -a`

### vim color scheme
```
# color themes locate in /usr/shared/vim/vim80/colors/
# in ~/.vimrc
colorscheme industry
```

### crontab - scheduled task

* `crond` is a daemon process for scheduled tasks

```
cat /etc/crontab 
# similar with
crontab -l
```

* `min hour day_of_month month day_of_week` 
```
#   30 * * * * user_root cmd # hourly 
#   30 1 * * * user_root cmd # daily 
#   30 1 * * 0 user_root cmd # weekly 
#   30 1 1 * * user_root cmd # monthly  - first day 1 AM 30 minutes

# edit task
crontab -e 
```


## Commands

### `help`, `man`, `info`

#### man

* sections of man `man 7 man`
  1. commands - can execute in shell
    * man ls # equals to man 1 ls
  2. system calls - called by kernel
  3. library calls - most of `libc` functions
  4. special files - files under `/dev`
  5. file formats and conventions - human readable fiels descriptions, e.g. `/etc/passwd`
  6. games
  7. macro packages and conventions - file system standard desc, net protocol, ASCII and other characters
  8. system management commands - like `mount`, mostly executed by `root`
  9. kernel routines - out of date

* all sections 
` man -a passwd`


#### help

* internal command - included by kernel
  * `help cd`
* external command
  * ` --help`

` type <cmd> ` can show type of command


#### info
it has more detail info than `help`.


* cp
```
cp -a
cp -p
```

* `tail -f` tracking the file change

* tar, gzip, bzip2
```
tar cf new.tar sourceDir
tar czf new.tar.gz sourceDir  # zip with gzip  .tgz
tar cjf new.tar.bz2 sourceDir # zip with bzip2	.tbz2
tar xf ..  -C ..
tar zxf ..  -C ..
tar jxf ..  -C ..
```

### screen
An simulator of tab in linux terminal.

```
screen -ls
screen -S myscreen
screen -d -r <screen>   # retach
```


* shortcuts for 'C-a'
```
c     # create new windows
C-a   # quich switch with most recent window
0-9
"     # list all selectable screens in current window
i     # show info of current window 
d     # detach
?     # help
A     # set title
k     # kill
```

### ps pstree top
```
ps -ef
ps -eLf           # L - LWP (light weight process) thread
ps -aux
```
* top
  * load avg: 1min 5min 15min
  * `s` - set refresh second
  * `o` - set order

## User & Group

### User

```
useradd szh
id szh
tail /etc/passwd
tail /etc/shadow
passwd szh
userdel -r szh

usermod -d /home/newhome/ szh

# password life-cycle
chage 
```

* file - `/etc/passwd /etc/shadow`

### Group

```
groupadd group1
usermod -g group1 szh
```
* file  - `/etc/group`

### su, sudo

```
su - szh  # - means not only user, also the environment. login with user
```

* sudo
  * visudo
  ```
  user    localhost/ALL=command1, command2    NeedPassword=ALL
  ```

### file permission

* does not work for `root` user
* r = 4, w = 2, x = 1
* default permission
  * `666 - \`umask\` ` - e.g. `666 - 022 = 644`

* change group
  ```
  chown [user1]:group1 file
  chgrp group1 file
  ```
* `chmod`
  ```
  chomd u=rx file
  ```

* SUID (`s`)
  * set uid, be used to binary file, execute as owner's permission 
  ```
  $ ls -l /usr/bin/passwd
  -rwsr-xr-x.    1    root    root /usr/bin/passwd
  ```
  * each user could change own password
* SGID
  * used to directory
  * for the files/folders new created under the folder, permission is set to current dir's groups permission
  * use case: shared folder
* SBIT (`t`)
  * used to directory
  * for the files/folders created under the folder, only myself and root could remove it
  ```
  $ ls -ld /tmp
  -rwxrwxrwt  root  root /tmp
  ```

## Network Configuration

1. net-tools - old way 
2. iproute2  - new way 

### net-tools
1. ifconfig
1. route
1. netstat

#### ifconfig

* eth0
* linux? may have diff names
  * eno1
  * ens
  * enp0s3
  * centos7

* switch network card to be * *

* change to `eth0` for network card
  ```
  vi /etc/default/grub
  # set value of `GRUB_CMDLINE_LINUX`  to be 
  # biosdevname=0   net.ifnames=0

  # refresh grup
  grub2-mkconfig -o /boot/grub2/grub.cfg

  ```
* change IP
```
ifconfig eth0 192.168.1.22  netmast 255.255.255.0   # change ip [netmask]

# reset ifconfig
ifdown eht0  
ifup   eth0  # ifconfig eth0 up
```

#### mii-tool

Check wired connection?

#### route

```
route -n

route del default gw 10.0.0.99 
route add default gw 10.0.0.1 

route add default 10.0.0.1    netmask 255.255.255.0 gw 10.21.1.1 

route add -host 10.0.0.1    gw 10.21.1.1 
route add -net  192.168.0.0 gw 10.21.1.2
```

### iproute2

1. ip
1. ss


## network trouble shooting

### ping
### traceroute
```
traceroute -w 1 www.baidu.com  # max wait 1 second
```
### mtr        - my traceroute, analysis data package
### nslookup   - domain 
* get ip from domain
* `dig`

### telnet     - host can access, but not service, check port
```
telnet www.baidu.com 80
```

### tcpdump    -  all tcp packages
```
tcpdump -i any -n port 80 [-w dump.log]
tcpdump -i any -n host 10.1.1.2 [and port 80]

```
* `-n` show ip instead of domain

### netstat    - service listen 
```
netstat -ntpl 
```
* `-n` show ip
* `-t` tcp
* `-p` process
* `-l` listen state services

### ss


## Network Service Management
Previous setting would be lost after OS/service restart.

* configuration files
  * ifcfg-eth0
  * etc/hosts
* show network status
  ```
  service network status
  service network restart # reset previous settings
  ```

To persistent the configuration:
1. sysV
2. systemd/systemctl

* `network` v.s. `NetworkManager` 
  * should use either `network` or `NetworkManager` (which is new in CentOS 7), not both
  * `network` is preferred in server management
  * turn `network`
    ```
    chkconfig --list network
    chkconfig --level 234 netowrk off
    ```
  * check `NetworkManager`
    ```
    systemctl list-unit-files NetworkManager.service
    systemctl disable NetworkManager
    ```
* `/etc/sysconfig/network-scripts/ifcfg-eth0`
  * `BOOTPROTO=dhcp`
    * `none` - static ip address
      * IPADDR, NETMASK, GATEWAY, DNS1, DNS2, DNS3
  * `DEVICE="eth0"`
  * `ONBOOT="yes"`
    * if it no, use `ifup` to start the network card
  * reload the config
    ```
    service network restart
    systemctl restart NetworkManager.service
    ```
  * check settings after reload
    * ifconfig eth0 (ip, netmask), route -n (gateway), nslookup (dsn)

* `hostname`
  ```
  hostname centos7.tempname
  hostnamectl set-hostname centos7.permanentname
  ```
  * **NOTE:** change `/etc/hosts` after hostname changes -  `127.0.0.1 centos7.newname`

## Liberay Management

### rpm

### deb

## Package Management

### yum

* epel is an extendent yum repo

```
yum install epel-release -y    

ls /etc/yum.repos.d/CentOS-Base.repo
wget -O /etc/yum/repos.d/CentOS-Base.repo http://mirrors.aliun.com/repo/Centos-7.repo
yum makecache
```

### apt


## Kernel

* yum 
  * `yum install kernel [3.10.0]`
  * or `yum update`
* rpm / source compile
  ```
  make menuconfig
  lscpu # check cpu
  make -j2 all
  make modules_install
  make install
  ```































