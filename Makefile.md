# Makefile

- [Makefile](#makefile)
    - [命令执行](#命令执行)
    - [Makefile 的变量的四种基本赋值方式：](#makefile-的变量的四种基本赋值方式)
    - [自动化变量](#自动化变量)
    - [path](#path)
    - [隐含规则](#隐含规则)
    - [ifeq 和 ifneq](#ifeq-和-ifneq)
    - [Function](#function)
- [TBD](#tbd)
- [Commands](#commands)
    - [set_target_properties](#set_target_properties)

Before issuing any command in a target rule set, there are certain special macros predefined −

- `$@` is the name of the file to be made.
- `$?` is the names of the changed dependents.

For example, we could use a rule as follows −

```
hello: main.cpp hello.cpp factorial.cpp
   $(CC) $(CFLAGS) $? $(LDFLAGS) -o $@

hello: main.cpp hello.cpp factorial.cpp
   $(CC) $(CFLAGS) $@.cpp $(LDFLAGS) -o $@
```

In this example, $@ represents hello and $? or $@.cpp picks up all the changed source files.
There are two more special macros used in the implicit rules. They are −

- `$<` the name of the related file that caused the action.
- `$*` the prefix shared by target and dependent files.

- 通常用 "-include" 来代替 "include" 来忽略文件不存在或者是无法创建的错误提示，使用格式如下： `-include <filename>`


### 命令执行

- 命令回显
  - 如果规则的命令行以字符“@”开始，则 make 在执行的时候就不会显示这个将要被执行的命令

- 在 Makefile 中书写在同一行中的多个命令属于一个完整的 shell 命令行，书写在独立行的一条命令是一个独立的 shell 命令行。因此：在一个规则的命令中命令行 “cd”改变目录不会对其后面的命令的执行产生影响。

- 变量“SHELL“的默认值时“/bin/sh”

- 并发执行命令
  - 通过 make 命令行选项 "-j" 或者 "--jobs" 来告诉 make 在同一时刻可以允许多条命令同时执行。

### Makefile 的变量的四种基本赋值方式：

- 简单赋值 ( := ) 编程语言中常规理解的赋值方式，只对当前语句的变量有效。
- 递归赋值 ( = ) 赋值语句可能影响多个变量，所有目标变量相关的其他变量都受影响。
- 条件赋值 ( ?= ) 如果变量未定义，则使用符号中的值定义变量。如果该变量已经赋值，则该赋值语句无效。
- 追加赋值 ( += ) 原变量用空格隔开的方式追加一个新值。

### 自动化变量

- $@	表示规则的目标文件名。如果目标是一个文档文件（Linux 中，一般成 .a 文件为文档文件，也成为静态的库文件），那么它代表这个文档的文件名。在多目标模式规则中，它代表的是触发规则被执行的文件名。
- $%	当目标文件是一个静态库文件时，代表静态库的一个成员名。
- $<	规则的第一个依赖的文件名。如果是一个目标文件使用隐含的规则来重建，则它代表由隐含规则加入的第一个依赖文件。
- $?	所有比目标文件更新的依赖文件列表，空格分隔。如果目标文件时静态库文件，代表的是库文件（.o 文件）。
- $^	代表的是所有依赖文件列表，使用空格分隔。如果目标是静态库文件，它所代表的只能是所有的库成员（.o 文件）名。 一个文件可重复的出现在目标的依赖中，变量“$^”只记录它的第一次引用的情况。就是说变量“$^”会去掉重复的依赖文件。
- $+	类似“$^”，但是它保留了依赖文件中重复出现的文件。主要用在程序链接时库的交叉引用场合。
- $*	在模式规则和静态模式规则中，代表“茎”。“茎”是目标模式中“%”所代表的部分（当文件名中存在目录时，“茎”也包含目录部分）。

- $(@D)	表示文件的目录部分（不包括斜杠）。如果 "$@" 表示的是 "dir/foo.o" 那么 "$(@D)" 表示的值就是 "dir"。如果 "$@" 不存在斜杠（文件在当前目录下），其值就是 "."。
- $(@F)	表示的是文件除目录外的部分（实际的文件名）。如果 "$@" 表示的是 "dir/foo.o"，那么 "$@F" 表示的值为 "dir"。
- $(*D), $(*F)	分别代表 "茎" 中的目录部分和文件名部分
- $(%D), $(%F)	当以 "archive(member)" 形式静态库为目标时，分别表示库文件成员 "member" 名中的目录部分和文件名部分。踏进对这种新型时的目标有效。
- $(<D), $(<F)	表示第一个依赖文件的目录部分和文件名部分。
- $(^D), $(^F)	分别表示所有依赖文件的目录部分和文件部分。
- $(+D), $(+F)	分别表示所有的依赖文件的目录部分和文件部分。
- $(?D), $(?F)	分别表示更新的依赖文件的目录部分和文件名部分。

### path

- VPATH 是搜索路径下所有的文件
- vpath 更像是添加了限制条件，会过滤出一部分再去寻找。
    ```
    vpath PATTERN DIRECTORIES 
    ```

### 隐含规则

中使用的变量可以分成两类：
- 1.代表一个程序的名字。例如：“CC”代表了编译器的这个可执行程序。
- 2.代表执行这个程序使用的参数.例如：变量“CFLAGS”。多个参数之间使用空格隔开。

下面我们来列举一下代表命令的变量，默认都是小写。
- AR：函数库打包程序，科创价静态库 .a 文档。
- AS：应用于汇编程序。
- CC：C 编译程序。
- CXX：C++编译程序。
- CO：从 RCS 中提取文件的程序。
- CPP：C程序的预处理器。
- FC：编译器和与处理函数 Fortran 源文件的编译器。
- GET：从CSSC 中提取文件程序。
- LEX：将Lex语言转变为 C 或 Ratfo 的程序。
- PC：Pascal 语言编译器。
- YACC：Yacc 文法分析器（针对于C语言）
- YACCR：Yacc 文法分析器。

E.g. `foo.o:foo.p` :
如果当前目录下恰好存在 foo.c 文件的时候，隐含规则会把 foo.c 当做是 foo.o 的依赖文件进行目标文件的重建。因为编译 .c 文件的隐含规则在编译 .p 文件之前，显然优先级也会越高。当 make 找到生成 foo.o 的文件之后，就不会再去寻找下一条规则。


### ifeq 和 ifneq

条件判断的使用方式如下：
ifeq (ARG1, ARG2)
ifeq 'ARG1' 'ARG2'
ifeq "ARG1" "ARG2"
ifeq "ARG1" 'ARG2'
ifeq 'ARG1' "ARG2"


- 因此当我们需要判断一个变量的值是否为空的时候需要使用“ifeq" 而不是“ifdef”。

### Function

- `$(<function> <arguments>)    或者是     ${<function> <arguments>}`
其中，function 是函数名，arguments 是函数的参数，参数之间要用逗号分隔开。而参数和函数名之间使用空格分开。调用函数的时候要使用字符“$”，后面可以跟小括号也可以使用花括号。

- $(patsubst <pattern>,<replacement>,<text>), 模式字符串替换函数
```
OBJ=$(patsubst %.c,%.o,1.c 2.c 3.c)
all:
    @echo $(OBJ)
```

- $(subst <from>,<to>,<text>), 字符串替换函数
- $(strip <string>), $(findstring <find>,<in>), $(filter <pattern>,<text>),$(filter-out <pattern>,<text>),$(sort <list>), $(word <n>,<text>)
- $(dir <names>) - 函数的功能是从文件名序列 names 中取出目录部分，如果没有 names 中没有 "/" ，取出的值为 "./" 。
- $(notdir <names>) - 从文件名序列 names 中取出非目录的部分
- $(suffix <names>), $(basename <names>), $(join <list1>,<list2>)
- $(wildcard PATTERN) 函数的功能是列出当前目录下所有符合模式的 PATTERN 格式的文件名. 执行 make 命令，可以得到当前函数下所有的 ".c " 和  ".h"  结尾的文件。
  ```shell
  OBJ=$(wildcard *.c  *.h)
  all:
    @echo $(OBJ)
  ```

- $(foreach <var>,<list>,<text>)
  - 函数的功能是：把参数<list>中的单词逐一取出放到参数<var>所指定的变量中，然后再执行<text>所包含的表达式。每一次<text>会返回一个字符串，循环过程中，<text>的返所返回的每个字符串会以空格分割，最后当整个循环结束的时候，<text>所返回的每个字符串所组成的整个字符串（以空格分隔）将会是 foreach 函数的返回值。
  - 执行 make 命令，我们得到的值是“a.o b.o c.o d.o”。
  ```
  name:=a b c d
  files:=$(foreach n,$(names),$(n).o)
  all:
    @echo $(files)
  ```
- $(if <condition>,<then-part>)或(if<condition>,<then-part>,<else-part>)
  ```
  OBJ:=foo.c
  OBJ:=$(if $(OBJ),$(OBJ),main.c)
  all:
      @echo $(OBJ)
  ```
- $(call <expression>,<parm1>,<parm2>,<parm3>,...)
  - call 函数是唯一一个可以用来创建新的参数化的函数。
  - make 执行这个函数的时候，expression参数中的变量$(1)、$(2)、$(3)等，会被参数parm1，parm2，parm3依次取代
  ```
  reverse = $(1) $(2)
  foo = $(call reverse,a,b)
  all：
      @echo $(foo)
  ```
- $(origin <variable>)
  - origin 函数不像其他的函数，它并不操作变量的值，它只是告诉你这个变量是哪里来的。
  ```
  下面是origin函数返回值：
  “undefined”：如果<variable>从来没有定义过，函数将返回这个值。
  “default”：如果<variable>是一个默认的定义，比如说“CC”这个变量。
  “environment”：如果<variable>是一个环境变量并且当Makefile被执行的时候，“-e”参数没有被打开。
  “file”：如果<variable>这个变量被定义在Makefile中，将会返回这个值。
  “command line”：如果<variable>这个变量是被命令执行的，将会被返回。
  “override”：如果<variable>是被override指示符重新定义的。
  “automatic”：如果<variable>是一个命令运行中的自动化变量。
  ```


# TBD
http://c.biancheng.net/view/7120.html


# Commands

### set_target_properties
