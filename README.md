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

