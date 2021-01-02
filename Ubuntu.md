# Ubuntu

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










