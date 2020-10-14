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


## Variables

- 变量的基本赋值

知道了如何定义，下面我们来说一下 Makefile 的变量的四种基本赋值方式：
 简单赋值 ( := ) 编程语言中常规理解的赋值方式，只对当前语句的变量有效。
 递归赋值 ( = ) 赋值语句可能影响多个变量，所有目标变量相关的其他变量都受影响。
 条件赋值 ( ?= ) 如果变量未定义，则使用符号中的值定义变量。如果该变量已经赋值，则该赋值语句无效。
 追加赋值 ( += ) 原变量用空格隔开的方式追加一个新值。


$@  表示规则的目标文件名。如果目标是一个文档文件（Linux 中，一般成 .a 文件为文档文件，也成为静态的库文件），
那么它代表这个文档的文件名。在多目标模式规则中，它代表的是触发规则被执行的文件名。
$%  当目标文件是一个静态库文件时，代表静态库的一个成员名。
$<  规则的第一个依赖的文件名。如果是一个目标文件使用隐含的规则来重建，则它代表由隐含规则加入的第一个依赖文件。
$?  所有比目标文件更新的依赖文件列表，空格分隔。如果目标文件时静态库文件，代表的是库文件（.o 文件）。
$^  代表的是所有依赖文件列表，使用空格分隔。如果目标是静态库文件，它所代表的只能是所有的库成员（.o 文件）名。
一个文件可重复的出现在目标的依赖中，变量“$^”只记录它的第一次引用的情况。就是说变量“$^”会去掉重复的依赖文件。
$+  类似“$^”，但是它保留了依赖文件中重复出现的文件。主要用在程序链接时库的交叉引用场合。
$*  在模式规则和静态模式规则中，代表“茎”。“茎”是目标模式中“%”所代表的部分（当文件名中存在目录时，
“茎”也包含目录部分）。


## VPATH的使用
在 Makefile 中可以这样写：
VPATH := src

我们可以这样理解，把 src 的值赋值给变量 VPATH，所以在执行 make 的时候会从 src 目录下找我们需要的文件。

当存在多个路径的时候我们可以这样写：
VPATH := src car

或者是
VPATH := src:car

多个路径之间要使用空格或者是冒号隔开，表示在多个路径下搜索文件。搜索的顺序为我们书写时的顺序，拿上面的例子来说，我们应该先搜索 src 目录下的文件，再搜索 car 目录下的文件。



## vpath的使用
在 src 路径下搜索文件 test.c。多路径的书写规则如下：
vpath test.c src car         或者是         vpath test.c src : car

多路径的用法其实和 VPATH 差不多，都是使用空格或者是冒号分隔开，搜索路径的顺序是先 src 目录，然后是 car 目录。

其次是用法二，命令格式如下：
vpath test.c

用法二的意思是清除符合文件 test.c 的搜索目录。

最后是用法三，命令格式如下：
vpath

vpath 单独使的意思是清除所有已被设置的文件搜索路径。



# TBD ... 

http://c.biancheng.net/view/7153.html

**FOCUS ON INTERVIEW SKILLS FIRST**

