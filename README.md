
<!-- MarkdownTOC autolink=true levels="1,2,3" -->

- [linux](#linux)
    - [check OS release version](#check-os-release-version)
    - [vim color scheme](#vim-color-scheme)
    - [crontab - scheduled task](#crontab---scheduled-task)
  - [logs /var/log](#logs-varlog)
  - [User & Group](#user--group)
    - [User](#user)
    - [Group](#group)
    - [su, sudo](#su-sudo)
    - [chmod, chown, SUID](#chmod-chown-suid)
  - [Network Configuration](#network-configuration)
    - [net-tools](#net-tools)
      - [ifconfig](#ifconfig)
      - [mii-tool](#mii-tool)
      - [route](#route)
    - [iproute2](#iproute2)
  - [network trouble shooting](#network-trouble-shooting)
    - [ping](#ping)
    - [traceroute](#traceroute)
    - [mtr        - my traceroute, analysis data package](#mtr----------my-traceroute-analysis-data-package)
    - [nslookup   - domain](#nslookup-----domain)
    - [telnet     - host can access, but not service, check port](#telnet-------host-can-access-but-not-service-check-port)
    - [tcpdump    -  all tcp packages](#tcpdump-------all-tcp-packages)
    - [netstat    - service listen, port listening](#netstat------service-listen-port-listening)
    - [ss](#ss)
  - [Network Service Management](#network-service-management)
  - [Liberay Management](#liberay-management)
    - [rpm](#rpm)
    - [deb](#deb)
  - [Package Management](#package-management)
    - [yum](#yum)
    - [apt](#apt)
    - [source code compile](#source-code-compile)
  - [Kernel](#kernel)
  - [memory / disk](#memory--disk)
    - [memory](#memory)
    - [disk](#disk)
  - [SELinux](#selinux)
  - [File System](#file-system)
  - [System info](#system-info)
    - [show archtecture info](#show-archtecture-info)
  - [Linux Startup](#linux-startup)
  - [Profile / Bashrc](#profile--bashrc)

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

[An example of setting up a process monitor and alert on a local system](https://www.redhat.com/sysadmin/linux-monitoring-and-alerting)


## logs /var/log

* messages
* dmesg
* secure
* cron

## User & Group

### User

```
useradd szh
id szh
tail /etc/passwd
tail /etc/shadow

passwd szh

userdel -r szh	// -r would remove home as well

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
su szh  # non-complete user switch
```

* sudo
  * visudo
  ```
  user    localhost/ALL=command1, command2    NeedPassword=ALL
  ```

### chmod, chown, SUID

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
  * eno1, ens, enp0s3(centos7)

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
ifconfig eth0 192.168.1.22  netmask 255.255.255.0   # change ip [netmask]
ifconfig eth0 up
ifconfig eth0 down

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
  - network issue or firewall

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
* wireshark can read .cap file saved by tcpdump

```
tcpdump -i any -n port 80 [-w dump.log]
tcpdump -i any -n host 10.1.1.2 [and port 80]

tcpdump -i any host www.baidu.com -w baidu.cap
tcpdump -r baidu.cap http

```
* `-n` show ip instead of domain

### netstat    - service listen, port listening
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

* `.deb` on Ubuntu

```
sudo dpkg -l t.deb # list
sudo dpkg -i t.deb # install
sudo dpkg -r t     # remove installed lib
```

## Package Management

### yum

* epel is an extended yum repo
```
yum install epel-release -y    

ls /etc/yum.repos.d/CentOS-Base.repo
wget -O /etc/yum/repos.d/CentOS-Base.repo http://mirrors.aliun.com/repo/Centos-7.repo
yum makecache
```

### apt

### source code compile

- general 3 steps
```
./configure [--prefix=/usr/local/myLib]
make -j4
make install
```

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

## memory / disk

### memory

* `free`
  * `-m g`

* swap - same concept on Windows is virtual memory
  - it's on disk, when memory is not enough

### disk

* `fdisk`
  - `-l` list
* `parted`
* `df`
* `du` - real size  - size of datablocks
* `ls` - logic size - size in inode
   ```
   dd if=/dev/zero bs=4M count=10 of=afile
   ls -lh afile # 40M
   du -h  afile  # 40M
   dd if=/dev/zero bs=4M count=10 seek=20 of=bfile  # file with 'hole'
   ls -lh bfile # 120M
   du -h  bfile # 40M
   ```
   - `ls` show the size info in inode 
   - `du` reads the count of datablock

## SELinux

```
getenforce
vi /etc/selinux/config
ps -Z
id -Z
ls -Z
```

## File System

* ext4 * super block and copy of super block - store info e.g. total file count * inode - stores permission, size, time
- file name is not stored in inode, it is stored in parent folder's inode, or (if there are too many files) may in
parent folder's datablock * datablock - stores content/data of the file - `ls` vs `du` - `ls` show the size info in
inode  - `du` reads the count of datablock * `ln -s src dest` * `facl, getfacl, setfacl` * xfx * NTFS

* `/ect/fstab` stores the mount devices to folders
* `free -m` show memory info

* `mdadm` software RAID

## System info

* `sar` system info
  - -u, -r, -d, -q 

* `iftop -P` show network status

### show archtecture info

```
# amd
uname -a
arch

# both amd and arm
cat /proc/cpuinfo
```
- i386 686 are 32bit, x86_64 is 64bit


## Linux Startup

* BIOS (choose startup device) - MBR(main boot area on disk/startup device) - BootLoader(grub) - kernel - systemd/init - SystemInit - shell

* show MBR content:
  ```
  dd if=/dev/sda of=mbr.bin bs=512 count=1
  hexdump -C mbr.bin`
  // end of 512 bytes is `55 aa` means the device is bootable
  ```

## Profile / Bashrc

- for all users: `/etc/profile` , `/etc/bashrc`
- `~/.bash_profile`, `~/.bashrc`
- `/etc/profile.d/` folder contains config files for diff version/type of shell

- login shell v.s. nologin shell
  - login shell : `su - xxx` , 4 files of profile and bashrc are all executed
    ```
    # order
    /etc/profile
    .bash_profile
    .bashrc
    /etc/bashrc.  # included by .bashrc
    ```
  - no-login shell: `sh xxx` , 2 files `/etc/bashrc` and `~/.bashrc` are executed
    ```
    # order
    .bashrc
    /etc/bashrc
    ```
    





















