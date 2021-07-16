# Ubuntu

- [Ubuntu](#ubuntu)
  - [apt](#apt)
  - [software / package install](#software--package-install)
  - [chinese input](#chinese-input)
  - [ssh server setup](#ssh-server-setup)
  - [Shell / Terminal](#shell--terminal)
  - [Ubuntu coredump apport](#ubuntu-coredump-apport)

## install CA root
- ref: https://askubuntu.com/questions/73287/how-do-i-install-a-root-certificate
```
cp root.crt /usr/local/shared/ca-certificates/extra/
sudo dpkg-reconfigure ca-certificates
sudo update-ca-certificates

# convert PEM to CRT
openssl x509 -in root.pem -inform PEM -out root.crt
```
>>>>>>> 33d66c9 (install certificate on Ubuntu)

## apt

Prefer `apt` than `apt-get`.

- show all version of package in repository
  ```
  apt -list -a pkg_name		# this would identify the installed one

  apt-cache madison pkg_name
  apt-cache policy pkg_name
  apt-cache showpkg pkg_name
  ```
- remove
  ```
  apt-remove  xxx  # remove package without configurations
  apt purge   xxx  # remove package and configurations
  ```

- common

```
apt update # update package repository
apt upgrade xxx # upgrade package
```


## software / package install

- cmake
  - download source: 

## chinese input

```
sudo apt-get install ibus ibus-clutter ibus-gtk ibus-gtk3 ibus-qt4
sudo apt-get install ibus-pinyin
ibus restart
ibus-setup
# system setting -> input
```

## ssh server setup

```
sudo apt install openssh-server
vi /etc/ssh/sshd_config       # change port
sudo /etc/init.d/ssh stop
sudo /etc/init.d/ssh start

ps aux | grep ssh
sudo iptables -A INPUT -p tcp --dport 2222 -j ACCEPT
```

## Shell / Terminal

- margin setting for Ubuntu terminal : https://askubuntu.com/questions/115762/increase-padding-in-gnome-terminal



## Ubuntu coredump apport 

- https://wiki.ubuntu.com/Apport
- How to enable apport
  - comment out following line in `/etc/apport/crashdb.conf`
    ```
    'problem_types': ['Bug', 'Package'],
    ```
- Core dump location, VM Ubuntu 20
  - it's in `/var/lib/apport/coredump`
  - it's not in `/var/crash` 
  - according to the documentation, after `apport` is enabled, system will generage core dump even `ulimit -c` is 0
    - check limit of running proc : `cat /proc/<pid>/limit`
- More
  ```
  cat /var/log/apport.log
  sysctl -w kernel.core_pattern
  ```
- run with core dump
  ```
  gdb ./myProgram -c <coredump>
  (gdb) bt
  (gdb) bt full
  (gdb) info locals
  (gdb) where
  ```








