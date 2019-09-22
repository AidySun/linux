<!-- MarkdownTOC -->

- CentOS Setup
  - Installation
  - Connect to Ethernet
  - Connect WiFi
  - Install GNOME
  - Pinyin Input
  - mirrors update
  - yum waiting
  - grub
    - reset root password

<!-- /MarkdownTOC -->


# CentOS Setup

## Installation
Download the CentOS 7 ISO file, create bootable USB with following command
```shell
dd if=CentOS_XXXX.iso of=/dev/sdb
```
> For other OS and detail steps, please refer to [How to Set Up a USB Key to Install CentOS](https://wiki.centos.org/HowTos/InstallFromUSBkey)

## Connect to Ethernet

Connect to wired network first.

```shell
vi /etc/sysconfig/network-scripts/ifcfg-enp0s25
```
add content similar with following:
```
  IPADDR=192.168.1.13 	# use static ip here
  NETMASK=255.255.255.0
  GATTEWAY=192.168.1.1
  BOOTPROTO=static
  ONBOOT=yes
```

`vi /etc/resolv.conf` and add nameservers:
```
nameserver 192.168.1.1
```

```
/etc/init.d/network restart
service network restart

ping www.baidu.com
```

## Connect WiFi

```shell
yum install iw
yum install wpa_supplicant
yum install net-tools

iw dev
iw wlp3s0 link
ifconfig
ip addr
ip link

ifconfig wlp3s0 up
ip link set dev wlp3s0 up

iw dev wlp3s0 scan | grep SSID

wpa_supplicant -B -i wlp3s0 -c <(wpa_passphrase "ssid" "password")
dhclient wlp3s0

ifconfig
ping www.baidu.com

```


## Install GNOME

```shell
yum groupinstall "X Window System"
yum grouplist
yum groupinstall "GNOME Desktop"
# yum groupinstall "Graphical Administration Tools"

startx

```

## Pinyin Input

```shell
yum install ibus
yum install im-chooser
imsettings-switch ibus
```
After adding Chinese input source in Settings application, the Chinese input only works when search applications, 
but not in other applications (Firefox, Sublime Text, Termina, Text Editor etc.)

Click Win/Mac key, type "input" to select `Input Method Selector`, and select `Use IBus` and log out.

```shell
# ~/.bash_profile
#export GTK_IM_MODULE=ibus
#export XMODIFILERS=@im=ibus
#export QT_IM_MODULE=ibus
```


## mirrors update

```
cd /ect/yum.repos.d
mv CentOS-Base.repo CentOS-BaseRepo.repo.bak
# download centos 7 from http://mirrors.163.com/.help/centos.html as CentOS-Base.repo
yum clean all
yum makecache
#yum update
```

## yum waiting

```shell
ps -ef
top

yum remove PackageKit -y
```

* no C compiler
```shell
yum -y install gcc gcc-c++ autoconf automake make 

```

## grub 
* change kernel boot config

* change boot order
```
grep ^menu /boot/grub2/grub.cfg
grub2-set-default 0 # order
grub2-editenv list
```
* /etc/default/grub
```
GRUB_CMDLINE_LINUX="xxxxx rhgb quiet biosdevname=0 net.ifnames=0"
rhgb - GUI
quiet - less info
```

### reset root password

* `e` to edit
* `linux16 /vm...`
  * CentOS6 - `single`
  * CentOS7 - `rd.break`
* Ctrl-x to start
* then
```
# current home is logic home, /sysroot is the real home on disk 
mouont -o remount,rw /sysroot
chroot /sysroot
echo 123456 | passwd --stdin root
```
* SELinux
  * vi /etc/selinux/config
  ```
  SELINUX=disabled
  ```
```
exit
reboot
```























