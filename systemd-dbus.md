# systemctl / systemd / dbus

1. [systemctl / systemd](#systemctl--systemd)
   1. [.service file](#service-file)
      1. [`[Unit]`](#unit)
      2. [`[Service]`](#service)
      3. [`[Install]`](#install)
2. [dbus](#dbus)
   1. [`busctl`](#busctl)



- Ref: https://ruanyifeng.com/blog/2016/03/systemd-tutorial-part-two.html


## systemctl / systemd
### .service file

#### `[Unit]`

Define dependencies and startup order.

- `Before` `After` defines the **startup order**, not dependency relationship
- `Wants` `Requires` define **dependency**. `Wants` is weak, `Requires` is strong
  - they don't define startup order, by default, the app and its dependency startup at the same time.

```
# self should startup **after** network.terget it it's startup
After=network.target

# 
Wants=sshd-keygen.service
```

#### `[Service]`

Defines startup behavior.

- `ExecStart`
  ```
  [Service]
  ExecStart=/bin/echo hihi
  ExecStart=
  ExecStart=-/bin/no-error
  
  Type=oneshot
  ExecStart=/usr/bin/touchpad-off start
  ExecStop=/usr/bin/touchpad-off stop
  RemainAfterExit=yes
  ```
  - empty `ExecStart=` cancel last `ExecStart`
  - `=-` means suppress error

- `Type`
  - simple: default, startup as main process
  - forking
  - oneshot
  - dbus
  - notify
  - idle

- `RemainAfterExit`
  - service keep executing after main process exits

- `KillMode`: behavior when receive `systemctl stop xx.service`
  - control-group: default, kill all sub-processes
  - process
  - mixed
  - none
    
- `Restart`: restart behavior 
  - no: default, no restart
  - on-success: exit code is 0
  - on-failure : exit code is not 0, include `on-abnormal`
  - on-abnormal: exit by signal or timeout
  - on-abort: no terminal signal was caught
  - on-watchdog: exit by timeout
  - always

- `RestartSec`: seconds to wait before restarting the service


#### `[Install]`

- `WantedBy`: target of which this service belongs to
  - multi-user.target
  - graphical.target

- target's config
  - `systemctl cat multi-user.target`




- after config is changed, reload and restart service
  ```bash
  sudo systemctl daemon-reload
  sudo systemctl restart xxservice
  ```



## dbus

- ref: http://0pointer.net/blog/the-new-sd-bus-api-of-systemd.html

### `busctl`

```shell
busctl
busctl tree org.freedesktop.dbus

# show interfaces/methods/properties/signals
busctl introspect <service> <object path>

# call a method
busctl call org.freedesktop.login1 /org/freedesktop/login1/session/_31 org.freedesktop.login1.Session Lock
busctl call <service> <object> <interace> <method> <signature> <par1> ...
busctl get-property ...

# capture iteractions
busctl --user capture <service> >> output.cap
wireshark outpu.cap
```





