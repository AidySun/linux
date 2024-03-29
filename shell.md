1. [parameters](#parameters)
2. [space in file name/path - IFS](#space-in-file-namepath---ifs)
3. [date](#date)
4. [path](#path)
5. [redirection](#redirection)
6. [grep](#grep)
7. [locate, which, whereis, find](#locate-which-whereis-find)
8. [gzip, bzip2, tar](#gzip-bzip2-tar)
9. [help, man, info](#help-man-info)
      1. [man](#man)
         1. [zh\_CN manpages](#zh_cn-manpages)
      2. [help](#help)
      3. [info](#info)
10. [Parameters](#parameters-1)
    1. [$@ v.s. $\*](#-vs-)
11. [cp, tail, tar, gzip](#cp-tail-tar-gzip)
12. [screen](#screen)
13. [ps pstree top (process management)](#ps-pstree-top-process-management)
    1. [lsof](#lsof)
14. [nice renice job](#nice-renice-job)
15. [kill](#kill)
16. [nohup deamon](#nohup-deamon)
17. [systemctl / service](#systemctl--service)
18. [command](#command)

# Shell


## parameters

- parameters in shell funtion:

```shell
    $1 ~ $9 - positional parameter
    $$ - current process id 
    $# - parameter number
    $0 - the current shell
    $? - exit code of last command
    $* $@ - the same, all parameters
    "$*" - "$1c$2c$3", c is the first char in IFS
    "$@" - "$1" "$2" "$3", is normal use
```

## space in file name/path - IFS

```
IFS=$'\n'
for f in `ls *.txt` do
  echo "$f"
  # file "a b" will be treated as two files by default
  # reason: space and tab will be treated as separator by default
  # solution: set IFS=$'\n'
done
```

## date

```
START_TIME=$(date -u +%s)
END_TIME=$(date -u +%s)
DURATION=$(echo "$END_TIME - $START_TIME" | bc)
PLATFORM=linux
if [ "${PLATFORM}" == "osx" ]; then
    echo "duration: $(date -u -r ${DURATION} +"%T")"
else
    echo "duration: $(date -u -d @${DURATION} +"%T")"
fi
```

- `+%c` : format as local time
- `-d @606 +"%T"` : convert seconds since epoch to a date, prefix `@` is required

## path

- path of the sh file

```
MY_PATH=`dirname $0`
```

- environment variable of a process :

```
cat /proc/28818/environ | tr '\0' '\n'
```

```
./run.sh parm1 parm2 

echo "$0"
# run.sh

DIR_SCRIPT=$(realpath -P $(dirname $0))
# realpath will return /absolute/path/of/run.sh
# dirname will return /absolute/path/of/run.sh


DIR_BUILD=$(pwd)
# 

```

## redirection

```
./a.sh >> /dev/null 2>&1 
```

- `0, 1, 2` mapping to `stdout, stdin, stderr`

## grep

- grep with file extension

```
grep -r --include=\*.txt 'searchterm' ./
```

- grep with depth, together with `find`

```
find . -maxdepth 2 [-type f "*.txt"] -exec grep what_to_find {} \;
grep what_to_find `find . -maxdepth 2 -type f`
```

## locate, which, whereis, find

- <https://www.madebygps.com/an-intro-to-finding-things-in-linux/>
- `locate [keyword]`: search entire filesystem and locate every occurrence of keyword. It uses a database that is usually updated every one day.
  - use command `updatedb` to update the locate db manually.
- `whereis [binary]`: returns binaries location, its source and man page if available.
- `which [binary]`: search binary location from `PATH` variable

## gzip, bzip2, tar

- `gzip file`: compress and replace the original file
  - `gunzip file`
  - `zcat file.gz` or `gunzip -c xxx.gz` to cat the content in file.gz
- `bzip2 file` is similar to `gzip` with a diff algorithm
- `tar`: archive multiple files into a one large file

  ```
  c - create
  x - exact
  r - append file to a tar
  t - list file in a tar
  ```

  - `tar xf a.tar --wildcards 'src/ProjectB/*'` : only exact files matches wildcards

## help, man, info

#### man

- sections of man `man 7 man`
  1. commands - can execute in shell
      - man ls # equals to man 1 ls
  2. system calls - called by kernel
  3. library calls - most of `libc` functions
  4. special files - files under `/dev`
  5. file formats and conventions - human readable fiels descriptions, e.g. `/etc/passwd`
  6. games
  7. macro packages and conventions - file system standard desc, net protocol, ASCII and other characters
  8. system management commands - like `mount`, mostly executed by `root`
  9. kernel routines - out of date

- all sections
`man -a passwd`

##### zh_CN manpages

```
apt install manpages-zh
alias manzh="man -L zh_CN.utf8 "
```

#### help

- internal command - included by kernel
  - `help cd`
- external command
  - `--help`

` type <cmd> ` can show type of command

#### info

- it has more detail info than `help`.

## Parameters

### $@ v.s. $*

<https://stackoverflow.com/a/12316565>

- prefer "%@" for common cases. Also double quotes with variable ("$word").

```
$ set -- "arg  1" "arg  2" "arg  3"

$ for word in $*; do echo "$word"; done
arg
1
arg
2
arg
3

$ for word in $@; do echo "$word"; done
arg
1
arg
2
arg
3

$ for word in "$*"; do echo "$word"; done
arg  1 arg  2 arg  3

$ for word in "$@"; do echo "$word"; done
arg  1
arg  2
arg  3
```

## cp, tail, tar, gzip

- cp

```
cp -a // archive, same as -dR --preserve=all
cp -p // --preserve=mode,ownership,timestamps
cp -P // no-dereference to symble links, keep soft link
```

- `tail -f` tracking the file change

- tar, gzip, bzip2

```
tar cf  new.tar     sourceDir
tar czf new.tar.gz  sourceDir   # zip with gzip. Ext .tgz = .tar.gz
tar cjf new.tar.bz2 sourceDir   # zip with bzip2. Ext .tbz2 = .tar.bz2
tar xf  .. -C ..
tar zxf .. -C ..
tar jxf .. -C ..
```

- `z` - gz, tgz; `j` - bz2, tbz2

## screen

- An simulator of tab in linux terminal.

```
screen -ls
screen -S myscreen
screen -d -r <screen>   # retach
```

- shortcuts for 'C-a'

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

## ps pstree top (process management)

- `ps`

  ```
  ps -ef
  ps -eLf   # L - LWP (light weight process) thread
  ps aux    # a: all user's process, u: current user, x: not attached to terminal
  ```

- `top`
  - load avg: 1min 5min 15min
  - `s` - set refresh second
  - `o` - set order

  ```
  top -p <process_id>
  ```

### lsof

- show open files

  ```shell
  # e.g. show files opened by <pid>
  lsof -p <pid>
  ```

## nice renice job

- nice range -20 to 19, the lower the high priority
- `echo $$` - current pid
- nice -n 10 ./a.sh
- renice -n 10 <pid>
- ./a.sh &
- jobs
- fg <index>
- ctrl + z # stop/hang a front ground process
- jobs
- bg/fg <index> # rerun stopped process

## kill

- Two ways of inter-process-communication
  - pipe
  - signal

- list signals : ` kill -l `

- ctrl+c = 2)SIGINT

```
kill -9 <pid>
```

## nohup deamon

- nohup - process won't exit if its terminal is closed

```
nohup cmd & # output to nohub.out
```

- deamon
  - same process as nohub, when terminal is closed, process's parent is changed to be 1
  - deamon process's directory is changed to be `/`

- `ls /proc/<pid>`

## systemctl / service

- service management tool
- service and target are located under `/usr/lib/systemd/system`
  - `vi sshd.service`
  - `systemctl get-default`
- `service` - CentOS 6
  - `/etc/init.d`
- `systemctl` - CentOS 7
  - `/usr/lib/systemd/system`
  - `systemctl status|start|stop|restart|enable|disbale <service>`  # e.g. sshd.service, network.service
    - `enable` - start on login

- `chkconfig --list`
- init

  ```
  init 0 # poweroff
  init 3 # multi user mode in console, 2 without network
  init 6 # reboot
  ```

## command

- check 'command' exist:
  - `if command -v wget &> /dev/null; then`

# if

- `if [ -t 1 ] ; then`
  - The specific subcommand -t tests a file descriptor to see if it is attached to a terminal.
    The file descriptor 1 is where the script's output is going (aka "standard output" or "stdout" for short).
    So -t 1 is true and [ -t 1 ] returns success if and only if the output of the script is going to a
    terminal (instead of into a file or pipe or something).
