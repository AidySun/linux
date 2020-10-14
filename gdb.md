# GDB


*`g++ -g test.cpp`: -g : generate source code level debug info*

## install

### [mac](https://zhuanlan.zhihu.com/p/68398728)


## Launch

- `gdb` then using `file` or `exec-file` to load executable file
- `gdb program_name`
  - `> run parameter` to set input parameters
  - or `set args parameters` then `run`
- attach/detach to existing process

  ```
  gdb attach pid
  gdb -p pid			# pidof myexe

  # 2 steps to detach
  detach
  quit / q
  ```
- core dump
  ```
  ulimit -a   # show core file size, 0 is off
  gdb program.exe core
  ```
- if a running process doesn't have debug info
  ```
  $ gdb
  (gdb) file program_with_same_code_and_compiled_with_debug_info
  (gdb) attach PID
  ```

## gdb options

- `-q / -quiet / -silent` : don't print GDB version and intro info
- `-cd dir` : change GDB work dir

- `n` step over
- `s` step into
- `finish` finish current function, step out?
- `continue / c` , `fg` run to next breakpoint
- `skip`
  - `skip function add`
  - `skip file add.c`
  - `info skip`, `skip delete/enable/disable [num]`
- `list` show source, `l 19,39`: show line 19-39 code
  - `l test.cpp:22`

## breakpoints

- list `info breakpoints`
- file line number `b main.c:9 if b==0`
  - change condition `condition 1 b==2`, `1` is the index of breakpoint
- `b func_name`

- **rbreak** : breakpoints with regex
  - usage : `rbreak file:regex`
  ```
  rbreak main.c:.   // all functions in main.c
  ```
- `ignore 1 10` : ignore the 1st breakpoint 10 hits

### enable/disable

```
disable     # disable all breakpoints
disable file:line_num
enable
enable delete break_num
```

### clear/delete

- clear vs delete
```
clear              # clear all breakpoints
clear file:function
delete             # delete all breakpoints, watchpoints and cachepoints
delete break_num
```

## print

```
p *d@10    // print *d with length 10 (or varaible)
p a
p/x a

set $index=0
p d[$index++]
```

- `$` is last variable

```
p *linkNode
p *$.next
```

常见格式控制字符如下：

x 按十六进制格式显示变量。
d 按十进制格式显示变量。
u 按十六进制格式显示无符号整型。
o 按八进制格式显示变量。
t 按二进制格式显示变量。
a 按十六进制格式显示变量。
c 按字符格式显示变量。
f 按浮点数格式显示变量。


## examine

* show value of memory addr: usage `x/[n][f][u] addr`

```
(gdb) x/4tb &e
```

## diaplay

Auto show variable value when break

```
display e
into display
delete display num
disable display num
```

## source code

- `dir ./tmp` - change source code folder
- 你编译好的程序文件，放到了另外一台机器上进行调试，或者你的源码文件全都移动到了另外一个目录，怎么办呢?
  原来的源码路径是什么呢？借助`readelf`命令可以知道：

```
$ readelf main -p .debug_str
  [     0]  long unsigned int
  [    12]  short int
  [    1c]  /home/hyb/workspaces/gdb/sourceCode
  [    40]  main.c
(gdb) set substitute-path /home/hyb/workspaces/gdb/sourceCode /home/hyb/workspaces/gdb/sourceCode/temp
(gdb) show substitute-path
List of all source path substitution rules:
  `/home/hyb/workspaces/gdb/sourceCode' -> `/home/hyb/workspaces/gdb/sourceCode/temp'.
```

- `edit func_name` edit source code

## Text User Interface

- `gdb main -tui`













