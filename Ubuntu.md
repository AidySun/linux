# Ubuntu

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












