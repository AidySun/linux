
<!-- MarkdownTOC autolink=true levels="1,2,3" -->

- [linux](#linux)
        - [check OS release version](#check-os-release-version)
        - [vim color scheme](#vim-color-scheme)
        - [crontab - scheduled task](#crontab---scheduled-task)
    - [Commands](#commands)
        - [`help`, `man`, `info`](#help-man-info)
        - [cp, tail, tar, gzip](#cp-tail-tar-gzip)
        - [screen](#screen)
        - [ps pstree top \(process management\)](#ps-pstree-top-process-management)
        - [nice renice job](#nice-renice-job)
        - [kill](#kill)
        - [nohup deamon](#nohup-deamon)
        - [systemctl / service](#systemctl--service)
    - [logs /var/log](#logs-varlog)
    - [User & Group](#user--group)
        - [User](#user)
        - [Group](#group)
        - [su, sudo](#su-sudo)
        - [chmod, chown, SUID](#chmod-chown-suid)
    - [Network Configuration](#network-configuration)
        - [net-tools](#net-tools)
        - [iproute2](#iproute2)
    - [network trouble shooting](#network-trouble-shooting)
        - [ping](#ping)
        - [traceroute](#traceroute)
        - [mtr        - my traceroute, analysis data package](#mtr---my-traceroute-analysis-data-package)
        - [nslookup   - domain](#nslookup---domain)
        - [telnet     - host can access, but not service, check port](#telnet---host-can-access-but-not-service-check-port)
        - [tcpdump    -  all tcp packages](#tcpdump---all-tcp-packages)
        - [netstat    - service listen, port listening](#netstat---service-listen-port-listening)
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
    - [Linux Startup](#linux-startup)
- [Shell](#shell)
    - [Shell script execution](#shell-script-execution)
    - [Redirection](#redirection)
    - [Variable](#variable)
        - [System variable](#system-variable)
    - [Shell Syntax](#shell-syntax)
        - [Sed & Awk](#sed--awk)
    - [Service Management](#service-management)
        - [iptables](#iptables)

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

* 	all sections 
` man -a passwd`

##### zh_CN manpages

```
apt install manpages-zh
alias manzh="man -L zh_CN.utf8 "
```

#### help

* internal command - included by kernel
  * `help cd`
* external command
  * ` --help`

` type <cmd> ` can show type of command


#### info

* it has more detail info than `help`.

### cp, tail, tar, gzip
* cp
```
cp -a
cp -p
```

* `tail -f` tracking the file change

* tar, gzip, bzip2
```
tar cf  new.tar     sourceDir
tar czf new.tar.gz  sourceDir   # zip with gzip. Ext .tgz = .tar.gz
tar cjf new.tar.bz2 sourceDir   # zip with bzip2. Ext .tbz2 = .tar.bz2
tar xf  .. -C ..
tar zxf .. -C ..
tar jxf .. -C ..
```
  * `z` - gz, tgz; `j` - bz2, tbz2

### screen

* An simulator of tab in linux terminal.

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

### ps pstree top (process management)
```
ps -ef
ps -eLf           # L - LWP (light weight process) thread
ps -aux
```
* top
  * load avg: 1min 5min 15min
  * `s` - set refresh second
  * `o` - set order
  ```
  top -p <process_id>
  ```

### nice renice job

* nice range -20 to 19, the lower the high priority
* `echo $$` - current pid
* nice -n 10 ./a.sh
* renice -n 10 <pid>
* ./a.sh &
* jobs
* fg <index>
* ctrl + z # stop/hang a front ground process 
* jobs
* bg/fg <index> # rerun stopped process

### kill

- Two ways of inter-process-communication
  - pipe
  - signal

- list signals : ` kill -l `

* ctrl+c = 2)SIGINT
```
kill -9 <pid>
```

### nohup deamon

* nohup - process won't exit if its terminal is closed
```
nohup cmd & # output to nohub.out
```

* deamon
  * same process as nohub, when terminal is closed, process's parent is changed to be 1
  * deamon process's directory is changed to be `/`

* `ls /proc/<pid>`


### systemctl / service

* service management tool
* service and target are located under `/usr/lib/systemd/system`
  * `vi sshd.service`
  * `systemctl get-default`
* `service` - CentOS 6
  * `/etc/init.d`
* `systemctl` - CentOS 7
  * `/usr/lib/systemd/system`
  * `systemctl status|start|stop|restart|enable|disbale <service>`  # e.g. sshd.service, network.service
    * `enable` - start on login

* `chkconfig --list`
* init
  ```
  init 0 # poweroff
  init 3 # multi user mode in console, 2 without network
  init 6 # reboot
  ```


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

* ext4
  * super block and copy of super block
    - store info e.g. total file count
  * inode
    - stores permission, size, time
    - file name is not stored in inode, it is stored in parent folder's inode, or (if there are too many files) may in parent folder's datablock
  * datablock
    - stores content/data of the file
    - `ls` vs `du`
      - `ls` show the size info in inode 
      - `du` reads the count of datablock
  * `ln -s src dest`
  * `facl, getfacl, setfacl`
* xfx
* NTFS

* `/ect/fstab` stores the mount devices to folders
* `free -m` show memory info

* `mdadm` software RAID

## System info

* `sar` system info
  - -u, -r, -d, -q 

* `iftop -P` show network status

## Linux Startup

* BIOS - MBR - BootLoader(grub) - kernel - systemd - SystemInit - shell
* `hexdump -C mbr.bin`
  -  end of 512 bytes is `55 aa` means the device is bootable

# Shell

* *Sha-Bang* : `#!/bin/bash`

## Shell script execution

```
# child bash process will be created to execute the script, `cd /tmp` won't affect executing pwd
bash ./f.sh
./f.sh

# executed under current process, `cd /tmp` will change current pwd
shource ./f.sh
. f.sh
```

* build-in commands won't create child shell process, e.g. `ls cd`.


## Redirection

* `2>` error
* `&>` all output

* input & output direction together
```
cat > email.txt << EOF
Hello A,
This is B. Nice to meet you.
EOF
```

## Variable

- varName=valud, `a=123`, no space around `=`
- let, `let a=10+20`, *calculation in shell is slow*
- expression result, `letc=$(ls -l .)`, or `letc=\`ls -l .\``


- variable scope: only current bash
  - `unset` to unset a variable
  - `export` extend the scope to child-shell

### System variable

- `env` - show system variable
  - capitalized variables are the default variables
- predefined variable
  - `$?` - last cmd return code
  - `$$` - current process pid
  - `$0` - current process name

- position var
  - `$1 ... ${10}`
  - default val for empty var `var2=${2-_}`

* Enviroment Configuration

* Execute order 
  - /etc/profile
  - /etc/profile.d/
  - ~/.bash_profile
  - ~/.bashrc
  - /etc/bashrc

* login shell `su - user` will use all config files, no-login shell `su user` will use bashrc
```
su - root # all 4 files (profile and bashrc) will be used, RECOMENDED
su root   # 2 bashrc will be used (.bashrc, /etc/bashrc), not recomended since the config were not wholely executed
```

## Shell Syntax

#### Array

```
IPTS=( 10.0.0.1 127.0.0.1 )
echo ${IPTS[@]}   # echo all items
echo ${#IPTS[@]}   # echo array len
echo ${IPTS[0]}   # echo first item
```

#### Number, mathmatic operator

```
expr 3+4	# expr only supports integer
let var1=10
(( a = 10 ))
(( a++ ))
echo $(( 10+2 ))
```

#### Special Symbol

- `()` 
  - will create a child shell,  `( var1abc )`
  - cmd execute result , `ret=$(ls)`
  - array
  - (()) math calculation

- `[]`
  - `[[ 5 > 4 ]]`
  - `[ 5 -gt 4 ]`
  - see also TEST

- `{}`
  - range `echo {0..9}`
  - replace `cp ./abc{.txt,.bak}`

* Test

  - `[]` is the simplized `test` cmd
  - `[[]]` supports ` < > && ||`

#### case

```
case "$1" in
    "start"|"START")
      echo "y"
      ;;
    *)
      echo "Usage: $0 {start|stop|restart}"
      ;;
esac
```

#### For / While

- shell style
```
for name in `ls *.mp3`
do
  mv $name $(basebame $name .mp3).mp4
done
```
  - `basename filename ext`

- C style

```
for (( i=1; i<=10; i++ ))
do
	echo "hi"
done
```
- While

```
while [ $# -gt 0 ]
do
    if [ $1 -eq help ] ; then
    	echo "has help"
    fi

    echo "SHIFT to next parameter"
    shift
done
```

#### Function

```
function chpid() {
	local i ## declare i is local to avoid conflict

	for i in $*
	do
	  [ -d "/proc/$i" ] && return 0
	done
	return 1
}
```

- built-in function `/etc/init.d/functions`
- `source filename` to load functions

* `ulimit -a` show resource limit of users
* `nice renice` adjust CPU resource

* Signal
  - `kill` send 15 to application
  - `Ctrl+C` is signal 2
  - 9 is not block / catchable / trapable

```
trap "catched signal 15" 15
trap "catched signal 2" 2
```

#### Schedule Task

- `at` once task
  ```
  at 18:30
  at> echo "it is time to run task"
  at> <EOT> 
  # Ctrl+D to EOT

  atq # show at queue
  ```

- Periodic task `cron`
  ```
  $ crontab -e
  * * * * * /usr/bin/date >> taskoutput.log

  $ tail /var/log/cron       # show cron edit history
  ```

### Sed & Awk

They are lines editor, while vim is full text editor.

- sed v.s. awk
  - awk prefer normal text (formatted with seperators)
  - sed handles un-formatted text

#### Sed

- -n : supress the print of each line
- N; read next line
- P; output from 1st char to 1st \n
- D; delete from 1st char to 1st \n

- only print replaced lines: `sed -n 's/aa/bb/p'`
- only replaced 2nd matched item: `sed 's/aa/bb/2'`

- =; print line number
- c; change matched line
- a; append to the next line of matched line
- r; read from file to next line of matched line
- n; skip
- w; write matched lines to file
- delete matched lines: `sed '/ab/d'`

```
sed 'N;s/\n//;s/hello bash/hello sed/;P;D' a.txt
```

- store mode
  - h, H : text mode -> store mode (h is replace, H is append)
  - g, G : store mode -> text mode
  - x : exchange text mode and store mode

```
# revise order

sed -n '1!G;h;$p'
sed '1!G;h;$!d'
```

#### Awk

- -F : set seperator char `awk -F "'" '/^menu/{ print x++, $0 } a.txt `


## Service Management

- change user password : `echo 12345 | passwd --stdin user1`

### iptables

```
iptables -vnL # same as iptable -t filter -vnL
iptables -A INPUT -s 10.0.0.1 -j ACCEPT 
iptables -A INPUT -s 10.0.0.1 -j DROP   # order matters, first matched rule will be used
# -A : append at end  -I : insert at top

```
- common usage: default policy is DROP, only allow some ips
```
iptables -P INPUT DROP
```

- `/etc/sysconfig/iptables`
  - `iptables-save` show current config in memory
  - save to file: `iptables-save > /etc/sysconfig/iptables`
  - `service iptables start` to start service after reboot

- yum / rpm

```
yum install iptables-services
rpm -ql iptables-services   # show detail info of package
```
- show service status
```
systemctl status firewalld.service
systemctl start firewalld.service
```

#### selinux

```
$ getenforce
Permissive
```
- if selinux is off, some settings may not be recognezied after enable again
  - solution `touch /.autorelabel`, `grub rd.break , genhomedircon`

#### Service

- check port of a service 
  - `grep telnet /etc/services`

- `systemctl status | start | stop | restart | enable | disable sshd.service`

#### tcpdump

```
tcpdump -i any port 2222 -s 1500 -tttt -w /tmp/tcpdump.log
apt install wireshark
wireshark -r /tmp/tcpdump.log
```

#### ssh

- windows ssh client
  - putty
  - Xshell
  - SecureCRT

#### ftp

- /etc/vsftpd/
- /etc/vsftpd/ftpusers - black user list
- /etc/vstpd/user_list - black/white user list

#### man

```
man -k 
man 5  - check help of config file
```

#### useradd
```
useradd user1 -d /home/user1 -s /sbin/nologin
```







