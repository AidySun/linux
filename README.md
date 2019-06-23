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

* 
```
man ls # equals to man 1 ls
1 sys
2 
```

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




















