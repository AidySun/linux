f
rsync Command
You can also use rsync command which is a fast and extraordinarily versatile file copying tool. It can make copies across the network. The syntax is as follows:
$rsync -av /path/to/source /path/to/destination
-a : Archive mode i.e. copy a folder with all its permission and other information including recursive copy.
-v : Verbose mode.
-z : With this option, rsync compresses the file data as it is sent to the destination machine, which reduces the amount of data being transmitted — something that is useful over a slow connection.
Commands:
     1. date
          $ date +DATE:%y-%m-%d%nTIME:%H:%M:%S
          $ date 022118592012      // Set time to be 2012-02-21 18:59

 
     2. cal [calander]
          $ cal [month] [year]

 
     3. bc [caculater]
          $ bc
          $ scale=2     // num count after point
          $ 1/10
          $ .10
          $ quit
 
4. grep <key> [file]
 
 
Others:
1. shell 就是使用者接口, Linux 底下预设的使用者接口就是  bash shell
 
 
Commands:
1. man       - 在所有Unix Like 系统中，都可以用
     e.g. DATE(1)
     DATE 我们知道是指令的名称，  那么  (1) 代表什么呢？他代表的是『一般使用者可使用的指令』的意思
 
     
代号代表内容1使用者可以操作的指令或可执行文件2系统核心可呼叫的函数与工具等3一些常用的函数  (function)  与函式库(library)4装置档案的说明5设定档或者是某些档案的格式6游戏  (games)7惯例与协议等，例如  Linux  标准档案系统、  网络协议、  ASCII code 等等的说明内容8系统管理员可用的管理指令9跟 kernel  有关的文件
  
按键进行工作空格键向下翻一页[Page Down]向下翻一页[Page Up]向上翻一页[Home]去到第一页[End]去到最后一页/string向『下』搜寻  string 这个字符串，如果要搜寻  vbird  的话，就输入 /vbird?string向『上』搜寻  string 这个字符串n, N利用  / 或  ? 来搜寻字符串时，可以用  n 来继续下一个搜寻  (不论是  / 或  ?)  ，可以利用 N  来进行『反向』搜寻。举例来说，我以  /vbird  搜寻 vbird  字符串，  那么可以  n 继续往下查询，用  N 往上查询。若以  ?vbird  向上查询 vbird  字符串，  那我可以用  n 继续『向上』查询，用  N 反向查询。q结束这次的  man page
  
  
[root@linux ~]# whatis [ 指令或者是数据 ] <==相当于  man -f [指令或者是数据]
[root@linux ~ ]# apropos [ 指令或者是数据 ] <==相当于  man -k [指令或者是数据]
/usr/share/man
/etc/man.config 

 
 
2. info   -   在Linux 系统中
     
按键进行工作空格键向下翻一页[Page Down]向下翻一页[Page Up]向上翻一页[tab]在 node  之间移动，有  node 的地方，通常会以  * 显示。[Enter]当光标在  node 上面时，按下  Enter  可以进入该 node  。b移动光标到该  info 画面当中的第一个  node  处e移动光标到该  info 画面当中的最后一个  node  处n前往下一个  info page 处p前往上一个  info page 处u向上移动一层s(/)在 info page  当中进行搜寻h显示求助选单?指令一览表q结束这次的  info page
  
/usr/share/doc 下有一些说明文档  
 
3. sync  -  数据同步写入磁盘
 

 
4. shutdown, reboot, halt, poweroff - 关机,  重启
     shutdown -h 1:30 
 
5. ls -l passwd
          
文档属性连接数OwnerGroup容量Modify timeFile name-rw-r—r--1RootWheel1932Aug 19 2006passwd
  

 
第一个属性代表这个档案是『目录、档案或连结文件等等』：
��  当为[ d ]则是目录；
��  当为[ - ]则是档案；
��  若是[ l ]则表示为连结档 (link file)；
��  若是[ b ]则表示为装置文件里面的可供储存的接口设备；
��  若是[ c ]则表示为装置文件里面的串行端口设备，例如键盘、鼠标。  
 
若没有 [可执行 ]权限，则不可及进入这个目录
6. chgrp - 改变所属群组
   chown - 改变档案所属人
   chmod - 改变文档属性
 
 
 
在 Linux 底下，每一个档案或目录的文件名最长可以到达 255 的字符，加上完整路径时，最长可达 4096 个字符
Filesystem Hierarchy Standard (FHS) 标准:仅是规范出在根目录 ( / ) 底下各个主要的目录应该是要放置什么样的档案而已
 
Network File System (NFS) 
 
目录：
/usr 则是 一些程序安 装的目录
/etc ：这个目录是系统设定文件放置的地方， 包括您系统上的账号与密码 (/etc/passwd, /etc/shadow)，还有开机时所要用到的各项设定值  
除了 /bin 之外， /usr/local/bin, /usr/bin 也是放置『使用者可执行的 binary file 的目录』
/dev  在 Linux 系统上，任何装置与接口设备都是以档案的型态存在于这个目录当中的
/lib, /usr/lib, /usr/local/lib   系统会使用到的函式库放置的目录
/sbin, /usr/sbin, /usr/local/sbin   放置一些系统管理员才会动用到的执行指令
/srv  一些服务启动之后，这些服务所需要取用的数据目录
/tmp  序暂时放置档案的地方。 这个目录是任何人都能够存取的
 
至于  Linux 的正统档案系统则为 ext 2 ( Linux second extended file system, ext2fs ), 升级版ext3 (Third Extended File System) ，主要是增加了日志  (journaling) 的功能
 
在 Linux 系统当中，每个档案不止有档案的内容数据，还包括档案的种种属性，例如：所属群组、 所属使用者、能否执行、档案建立时间、档案特殊属性等等
ext2 规划出 inode 与 Block 来分别储存档案的属性 ( 放在 inode 当中 )与档案的内容 ( 放置在 Block area 当中 ).Block 是记录『档案内容数据』的区域，至于 inode 则是记录『该档案的相关属性，以及档案内容放置在哪一个 Block 之内』的信息
一块 partition 在 ext2 底下会被格式化为 inode table 与 block area 两个区域
 
inode的特殊作用
由于inode  号码与文件名分离，这种机制导致了一些  Unix/Linux系统特有的现象。
　　1.  有时，文件名包含特殊字符，无法正常删除。这时，直接删除  inode节点，就能起到删除文件的作用。
　　2.  移动文件或重命名文件，只是改变文件名，不影响  inode号码。
　　3.  打开一个文件以后，系统就以  inode号码来识别这个文件，不再考虑文件名。因此，通常来说，系统无法从  inode号码得知文件名。
第3  点使得软件更新变得简单，可以在不关闭软件的情况下进行更新，不需要重启。因为系统通过  inode号码，识别运行中的文件，不通过文件名。更新的时候，新版文件以同样的文件名，生成一个新的  inode，不会影响到运行中的文件。等到下一次运行这个软件的时候，文件名就自动指向新版文件，旧版文件的  inode则被回收。
 
文档3个时间属性：
modification time (mtime)：
當該檔案的『內容資料』變更時，就會更新這個時間！內容資料指的是檔案的內容，而不是檔案的屬性或權限喔！
 
status time (ctime)：
當該檔案的『狀態 (status)』改變時，就會更新這個時間，舉例來說，像是權限與屬性被更改了，都會更新這個時間啊。  
 
access time (atime)：
當『該檔案的內容被取用』時，就會更新這個讀取時間 (access)。舉例來說，我們使用 cat 去讀取 /etc/man.config ， 就會更新該檔案的 atime 了。
e.g. ls -l --time=atime /etc/man.config
 
touch - 修改文件时间属性
 
要注意的是， inode 本身并不纪录文件名，而是记录档案的相关属性，至于文件名则是记录在目录所属的 block 区域

ext2 有几个特色：
• Blocks 与  inodes 在一开始格式化时 (format) 就已经固定了；
• 一个  partition 能够容纳的档案数与 inode 有关；
• 一般来说，每  4Kbytes 的硬盘空间分配一个 inode ；
• 一个  inode 的大小为 128 bytes ；
• Block 为固定大小，目前支持  1024/2048/4096 bytes 等；
• Block 越大，则损耗的硬盘空间也越多。
• 关于单一档案： 若  block size=1024，最大容量为 16GB ，若 block size=4096，容量最大为  2TB；
• 关于整个  partition ： 若 block size=1024 ，则容量达 2TB，若  block size=4096，则容量达 32TB 。
• 文件名最长达  255 字符，完整文件名长达 4096 字符。  
 
Linux 上面通常采取异步处理 ( asynchronously )
df - display free disk space
将容量结果以易读的容量格式显示出来  df -h 
du - display disk usage statistics
 
Link File :
 
 1. hard link
最大的好处就是『安全！』如同上面提到的 /root/crontab 与 /etc/crontab 中， 不管哪一个档案被删除了，其实仅是移除一笔目录底下的档案关连性数据，并没有更动到原本档案的 inode 与 block 数据
 
使用 hard link 设定连结文件时，磁盘的空间与 inode 的数目都不会改变！ 由上面的说明来看，我们可以知道， hard link 
只是在某个目录下的 block 多写入一个关连数据
 
由于 hard link 是在同一个 partition 上面进行数据关连的建立，所以 hard link 是有限制的：
• 不能跨 Filesystem；
• 不能  hard link 到目录
一般情况下，文件名和 inode号码是 " 一一对应 "关系，每个  inode号码对应一个文件名。但是，  Unix/Linux系统允许，多个文件名指向同一个  inode号码。
这意味着，可以用不同的文件名访问同样的内容；对文件内容进行修改，会影响到所有文件名；但是，删除一个文件名，不影响另一个文件名的访问。这种情况就被称为  "硬链接  "（  hard link）。
这里顺便说一下目录文件的  "链接数  "。创建目录时，默认会生成两个目录项：  "."和 ".." 。前者的inode 号码就是当前目录的  inode号码，等同于当前目录的  "硬链接  "；后者的  inode号码就是当前目录的父目录的  inode号码，等同于父目录的  "硬链接  "。所以，任何一个目录的  "硬链接  "总数，总是等于  2加上它的子目录总数（含隐藏目录）。
  2. Symbolic Link (符号连结，亦即是快捷方式 ) 
Symbolic link 就是在建立一个独立的档案， 而这个档案会让数据的读取指向他 link 的那个档案内容
由 Symbolic link 所建立的档案为一个独立的新的档案，所以会占用掉 inode 与 block 
 
这意味着，文件A依赖于文件  B而存在，如果删除了文件  B，打开文件  A就会报错：  "No such file or directory"。这是软链接与硬链接最大的不同：文件  A指向文件  B的文件名，而不是文件  B的  inode号码，文件  B的  inode"链接数 " 不会因此发生变化。
 
 
 
[root@linux ~]# ln [-sf] 来源文件 目标文件
参数：
-s ：如果 ln 不加任何参数就进行连结，那就是 hard link，至于 -s 就是 symbolic link
-f ：如果  目标文件  存在时，就主动的将目标文件直接移除后再建立！
目录的相关操作： 
. 代表此层目录.. 代表上一层目录- 代表前一个工作目录~ 代表『目前使用者身份』所在的家目录~account 代表 account 这个使用者的家目录
 
pwd 是 Print Working Directory 的缩写

  

 
• cat 由第一行开始显示档案内容
• tac 从最后一行开始显示，可以看出  tac 是 cat  的倒着写！
• nl 显示的时候，顺道输出行号！
• more 一页一页的显示档案内容
• less 与  more 类似，但是比 more  更好的是，他可以往前翻页！
• head 只看头几行
• tail 只看尾巴几行
• od 以二进制的方式读取档案内容！  

 
那 么 whereis 到底是使用什么咚咚呢？为何搜寻的速度会比 find 快这么多？！ 其实那也没有什么！这是因为 Linux 系统会将系统内的所有档案都记录在一个数据库档案里面， 而当使用 whereis 或者是底下要说的 locate 时，都会以此数据库档案的内容为准， 因此，有的时后你还会发现使用这两个执行档时，会找到已经被杀掉的档案！ 而且也找不到最新的刚刚建立的档案呢！
可以直接使用 /usr/bin/updatedb 来更新数据库档案
find 是直接搜寻硬盘
 
 
find:
-exec 参数后面跟的是 command命令，注意点如下：
command命令的终止，使用 ';' (分号）来判定，在后面必须有一个 ';'
'{}'，使用 {}来表示文件名，也就是 find前面处理过程中过滤出来的文件，用于 command命令进行处理
特别强调，对于不同的系统，直接使用分号可能会有不同的意义， 使用转义符 '\'在分号前明确说明
举例：
1.查询所有保护字符串 “Hello”的文件
find / -exec grep "Hello" {} \;
2.删除所有临时文件
find / -name "*.tmp" -exec rm -f {} \;
。。。。。。。。
 
 
 
 
 
Command history:
1. history
    !315 - re-execute corresponding command
2. Ctrl + R
 

Linux 系统常见的压缩指令 ： 
1 compress 
2. gzip, zcat 
   gzip  参数：
-c ：将压缩的数据输出到屏幕上，可透过数据流重导向来处理；
-d ：解压缩的参数；
-t ：可以用来检验一个压缩档的一致性～看看档案有无错误；
-#   ：压缩等级， -1 最快，但是压缩比最差、 -9 最慢，但是压缩比最好！预设是  -6 ～
3 bzip2, bzcat 
4 tar 
     参数：
-c ：建立一个压缩档案的参数指令 (create 的意思 )；
-x ：解开一个压缩档案的参数指令！
-t ：查看 tarfile 里面的档案！
特别注意，在参数的下达中， c/x/t 仅能存在一个！不可同时存在！
因为不可能同时压缩与解压缩。
-z ：是否同时具有 gzip 的属性？亦即是否需要用 gzip 压缩？
-j ：是否同时具有 bzip2 的属性？亦即是否需要用 bzip2 压缩？
-v ：压缩的过程中显示档案！这个常用，但不建议用在背景执行过程！
-f ：使用档名，请留意，在 f 之后要立即接档名喔！不要再加参数！
例如使用『 tar -zcvfP tfile sfile 』就是错误的写法，要写成
『 tar -zcvPf tfile sfile 』才对喔！
-p ：使用原档案的原来属性（属性不会依据使用者而变）
-P ：可以使用绝对路径来压缩！
-N ：比后面接的日期 (yyyy/mm/dd)还要新的才会被打包进新建的档案中！
--exclude FILE ：在压缩的过程中，不要将  FILE 打包！
 
tar -cvf - /etc | tar -xvf -
# 这个动作有点像是  cp -r /etc /tmp 啦～依旧是有其有用途的！
tar -cvf new.tar ./
tar -xvf new.tar
5 dd - convert and copy a file
     [root@linux ~]# dd if="input_file" of="outptu_file" bs="block_size" count="number"
参数：
if ：就是 input file 啰～也可以是装置喔！
of：就是  output file 喔～也可以是装置；
6 cpio  - copy file to and from atchives
user$ find . -iname "file" | cpio -pmud backup/
 
 
vi 与 vim 
1. vi
     vi has three modes:
normal mode
edit mode
command mode : type : or / or ? in normal mode

 
page 343
 
2. in vim 
当我们按下 v 或者 V 或者 [Ctrl]+v 时， 这个时候光标移动过的地方就会开始反白，这三个按键的意义分别是： 区块选择的按键意义  
v 字符选择，会将光标经过的地方反白选择！  V 行选择，会将光标经过的行反白选择！  [Ctrl]+v 区块选择，可以用长方形的方式选择资料  y 将反白的地方复制起来  d 将反白的地方删除掉  

 
多档案编辑的按键  
:n 编辑下一个档案  :N 编辑上一个档案  :files 列出目前这个 vim 的开启的所有档案  

 
多窗口情况下的按键功能  
:sp [filename]开启一个新窗口，如果有加 filename， 表示在新窗口开启一个新档案，否则表示两个窗口为同一个档案内容 (同步显示 )。  [ctrl]+wj 按键的按法是：先按下 [ctrl] 不放， 再按下 w 后放开所有的按键，然后再按下 j ，则光标可移动到下方的窗口。  [ctrl]+wk 同上，不过光标移动到上面的窗口。  [ctrl]+wq 其实就是 :q 结束离开啦！ 举例来说，如果我想要结束下方的窗口，那么利用 [ctrl]+wj 移动到下方窗口后，按下 :q 即可离开， 也可以按下 [ctrl]+wq 啊！  
 
vim 的环境设定参数  
:set nu 还记得这个吧？！就是设定行号啊！取消的话，就是 :set nonu :set hlsearch 这个就是设定是否将搜寻的字符串反白的设定值。 默认值就是 hlsearch ，如果不想要反白，就 :set nohlsearch 。 :set autoindent是否自动缩排？ autoindent 就是自动缩排， 不想要缩排就 :set noautoindent 。  :set backup 是 否自动储存备份档？一般是 nobackup 的， 如果设定 backup 的话，那么当你更动任何一个档案时，则源文件会被另存成一个档名为 filename~ 的档案。 举例来说，我们编辑 hosts ，设定 :set backup ，那么当更动 hosts 时，在同目录下，就会产生 hosts~ 文件名的档案，记录原始的 hosts 档案内容～  :set ruler 还记得我们提到的右下角的一些状态列说明吗？ 这个 ruler 就是在显示或不显示该设定值的啦！  :set showmode 这个则是，是否要显示 --INSERT-- 之类的字眼在左下角的状态列。  :set backspace=(012) 一 般来说， 如果我们按下 i 进入编辑模式后，可以利用退格键 (backspace) 来删除任意字符的。 但是，某些 distribution 则不许如此。此时，我们就可以透过 backspace 来设定啰～ 当 backspace 为 2 时，就是可以删除任意值； 0 或 1 时，仅可删除刚刚输入的字符， 而无法删除原本就已经存在的文字了！  :set all 显示目前所有的环境参数设定值。  :syntax (off|on) 是否依据程序相关语法显示不同颜色？ 举例来说，在编辑一个纯文字文件时，如果开头是以 # 开始，那么该行就会变成蓝色。  
 
 
Bash Shell

Linux 使用的这一种版本就称为『 Bourne Again SHell (简称 bash) 』
 
  『设定』或者是『修改』 某个变量！很简单！用『等号 (=)』连接变量与他的内容 , 取消变量的方法为：『 unset 变量名称』 . export 将变量变成环境变量
在变量的设定当中，单引号与双引号的用途有何不同？ 单引号与双引号的最大不同在于双引号仍然可以保有变量的内容，但单引号内仅能是一般字符 ，而不会有特殊符号 
 
Q: 在指令下达的过程中， quote ( ` ) 这个符号代表的意义为何？
A: 在一串指令中，在 ` 之内的指令将会被先执行，而其执行出来的结果将做为外部的输入信息
 e.g. [root@linux ~]# ls -l `locate crontab`
如此一来，先以 locate 将文件名数据都列出来，再以 ls 指令来处理的意思啦
 
set - list all variables
PS1='\n[\w] \A \$ '       - 设置提示字符
 
user$ echo $?    - echo the return value of last command
 
special vars : 
��
$? exit code of last command
��
$0 to $9 arguments passed
��
"$*", "$@" all arguments (mostly quoted)
��
$# number of args
��
$$ current PID, $! last background PID
��
$PATH search path for programs
��
$IFS input field separator
 
 
 
export - change customized var to be env var, which can be used in sub bash 
 
type [command] - tell the type of the command. E.g. user$ type -a ls
 
• read 
要读取来自键盘输入的变量
[root@linux ~]# read [-pt] variable 参数：  -p ：后面可以接提示字符！  -t ：后面可以接等待的『秒数！』
e.g. user$ read -p "what's your name? " -t 30 myname
       user$ echo $myname
 

 
• declare / typeset 
declare 或 typeset 是一样的功能，就是在宣告变量的属性。
[root@linux ~]# declare [-aixr] variable 参数：  -a ：将后面的 variable 定义成为数组 (array) -i ：将后面接的 variable 定义成为整数数字 (integer) 
-x ：用法与 export 一样，就是将后面的 variable 变成环境变量；  -r ：将一个 variable 的变量设定成为 readonly ，该变量不可被更改内容，也不能 unset  
 

• 数组属性 array, 
一般来说，建议直接以 ${数组 } 的方式来读取
[root@linux ~]# var[1]="small min"
[root@linux ~]# var[2]="big min"
[root@linux ~]# var[3]="nice min"
[root@linux ~]# echo "${var[1]}, ${var[2]}, ${var[3]}"
 

变量format：
 user$ echo ${var##/text to be delete/}    -  ## means delete the longest matched text from begining, while # means delete the smallest matched text, and %% means delete from end
 user$ echo ${var//old str/new str}          - // means replace all matched text with new text, while / means one time only
 
档案系统及程序的限制关系： ulimit 


变量赋值：
变量设定方式str 没有设定str 为空字符串str 已设定非为空字符串var=${str-expr}var=exprvar=var=$strvar=${str:-expr}var=exprvar=exprvar=$strvar=${str+expr}var=exprvar=exprvar=exprvar=${str:+expr}var=exprvar=var=exprvar=${str=expr}str=expr var=exprstr 不变 var=str 不变 var=$strvar=${str:=expr}str=expr var=exprstr=expr var=exprstr 不变 var=$strvar=${str?expr}expr 输出至 stderrvar=  var=strvar=${str:?expr}expr 输出至 stderrexpr 输出至 stderr  var=str

history 
[root@linux ~]# !number [root@linux ~]# !command [root@linux ~]# !! 参数：  number ：执行第几笔指令的意思；  command ：由最近的指令向前搜寻『指令串开头为 command』的那个指令，并执行；  !! ：就是执行上一个指令 (相当于按 ↑按键后，按 Enter) 
 
source -   reload the setting file to current bash    
e.g. user$ source ~/.bash_profile
 

 
数据流重导向  (redirection)
 
1. 标准输入 (stdin) ：代码为  0 ，使用  < 或 <<  ； 
2. 标准输出 (stdout)：代码为  1 ，使用  > 或 >>  ； -  '>>' will append to the existed content, while '>' will clear first.
3. 标准错误输出 (stderr)：代码为  2 ，使用  2> 或 2>>  ； 
4.    using & to redirect both stdout and stderr.   
e.g. $ grep host /root/* &> resultWithStdoutAndStderr.txt

 
* > will clear the content first and then write the result; while >> will append the new result to existed content.

By default, stderr won't be passed to pipe, if users wants it be passed:
$ grep hosts /root/* 2>&1 | grep 'permission' > resultWithError.txt

双向重导向： tee 
tee [-a] file 参数：  -a ：以累加 (append) 的方式，将数据加入 file 当中！  
范例： [root@linux ~]# last | tee last.list | cut -d " " -f1 # 这个范例可以让我们将 last 的输出存一份到 last.list 档案中；  


 
/dev/null 是什么呢？ 基本上，那就有点像是一个『黑洞』的垃圾桶功能
 
 
MC SYSTEM如果我要将数据都写到同一个档案中呢？这个时候写法需要用到特殊写法，请注意底下的写法呦！
[dmtsai@linux ~]$ find /home -name testing > list 2> list <== 错误写法[dmtsai@linux ~]$ find /home -name testing > list 2>&1 <== 正确写法
特别留意这一点呢！同时写入同一个档案需要使用  2>&1 才对呦！
 
 
命令执行的判断依据： ; , &&, || 
 
管线命令 (pipe) - sympol '|'
仅能处理经由前一个指令传来的正确信息，也就是 standard output的信息，对于stderror 没有处理能力
 
撷取命令(cut, grep)：
cut  -  处理以行为单位，将一行信息中取出我们想要的
[root@linux ~]# cut -d'分隔字符 ' -f fields [root@linux ~]# cut -c 字符区间 参数：  -d ：后面接分隔字符。与 -f 一起使用；  -f ：依据 -d 的分隔字符将一段讯息分割成为数段，用 -f 取出第几段的意思；  -c ：以字符 (characters) 的单位取出固定字符区间；  范例：  
[root@linux ~]# echo $PATH | cut -d ':' -f 5 # 嘿嘿！如此一来，就会出现 /usr/local/bin 这个目录名称！  # 因为我们是以 : 作为分隔符，第五个就是 /usr/local/bin 啊！ 
grep －  处理以行为单位，若有我们想要的，就将该行取出来
[root@linux ~]# grep [-acinv] ' 搜寻字符串' filename 
参数： -a ：将 binary 档案以 text 档案的方式搜寻数据  -c ：计算找到 '搜寻字符串 ' 的次数  -i ：忽略大小写的不同，所以大小写视为相同  -n ：顺便输出行号  -v ：反向选择，亦即显示出没有 '搜寻字符串 ' 内容的那一行！  范例：  范例一：将 last 当中，有出现 root 的那一行就取出来；  [root@linux ~]# last | grep 'root' 范

 
排序命令： sort, wc (word count), uniq (unique) 
 


 
字符转换命令：
tr, col, join, paste, expand 
 
文件分割命令： split 
[root@linux ~]# split [-bl] file PREFIX 参数：  -b ：后面可接欲分割成的档案大小，可加单位，例如 b, k, m 等；  -l ：以行数来进行分割。  
e.g. user$ split -b 300k  ./myfile.txt   newfilename
 
范例二：如何将上面的三个小档案合成一个档案，档名为 termcapback [root@linux tmp]# cat termcap* >> termcapback # 很简单吧？就用数据流重导向就好啦！简单！  

xargs  - 它的作用是将参数列表转换成小块分段传递给其他命令，以避免参数列表过长的问题
例如，下面的命令：
rm`find/path -type f`
如果path 目录下文件过多就会因为 “参数列表过长 ”而报错无法执行。但改用 xargs以后，问题即获解决。
find/path -type f -print0|xargs-0rm
本例中xargs 将find产生的长串文件列表拆散成多个子串，然后对每个子串调用 rm。这样要比如下使用 find命令效率高的多。
find/path -type f -execrm'{}' \;
上面这条命令会对每个文件调用 "rm"命令。
 
 
 
 
 
关于减号 - 的用途 
管 线命令在 bash 的连续的处理程序中是相当重要的！另外，在 log file 的分析当中也是相当重要的一环， 所以请特别留意！另外，在管线命令当中，常常会使用到前一个指令的 stdout 作为这次的 stdin ， 某些指令需要用到文件名称 (例如 tar) 来进行处理时，该 stdin 与 stdout 可以利用减号 "-" 来替代， 举例来说
[root@linux ~]# tar -cvf - /home | tar -xvf - 
上 面这个例子是说：『我将 /home 里面的档案给他打包，但打包的数据不是纪录到档案，而是传送到 stdout； 经过管线后，将 tar -cvf - /home 传送给后面的 tar -xvf - 』。后面的这个 - 则是取用前一个指令的 stdout， 因此，我们就不需要使用 file 了
 
 
 
 
Regular Expression
 
\{n,m\}
找出含有 (es) (ess) (esss) 等等的字符串，注意，因为 * 可以是 0 个，所以 es
也是符合带搜寻字符串。另外，因为 * 为重复『前一个 RE 字符』的符号，
因此，在 * 之前必须要紧接着一个 RE 字符喔！例如任意字符则为 『 .*』 ！
连续 n 到 m 个的『前一个 RE 字符』
若为 \{n\} 则是连续 n 个的前一个 RE 字符，
若是 \{n,\} 则是连续 n 个以上的前一个 RE 字符！
范例：grep -n 'go\{2,3\}g' regular_express.txt
在 g 与 g 之间有 2 个到 3 个的 o 存在的字符串，亦即 (goog)(gooog)
字符集合的 RE 特殊字符的符号
 
 
『正规表示法的特殊字符』与一般在指令列输入指令的『万用字符』并不相同， 例如， 在万用字符当中 , *代表的是0~ 无限多个字符的意思，但是在正规表示法当中 , *则是重复0 到多个的前一个字符的意思
 
 
格式化打印：printf
 
sed - sed 可以分析  Standard Input (STDIN) 的数据
          e.g.  xpression$  cat _vimrc_bak | sed '5,$d' |tee _vimrc_for_diff
awk - awk 则比较倾向于一行当中分成数个『字段』来处理。因此， awk 相当的适合处理小型的数据数据处理
 
[root@linux ~]# diff [-bBi] from-file to-file
 
[root@linux ~]# cmp [-s] file1 file2
 
patch 
patch 这个指令与  diff 可是有密不可分.，用  diff 制作这个档案时，旧的档案必须是在前面，亦即是  diff oldfile newfile 才行
 
档案打印准备： pr
 
 

Shell Scripts
 
 第一行 #!/bin/bash 在宣告这个 script 使用的 shell 名称：  
 
If an user wants to execute the script in current path, the executing command should be like ". ./to.sh".
 
执行数值运算：
1. total=$(($firstnum*$secnum))
2. declare -i total = $firstnum*$secnum
 
 
 
test : 
测试的标志  代表意义  1. 关于某个档名的『类型』侦测 (存在与否 )，如 test -e filename  -e 该『档名』是否存在？ (常用 ) -f 该『档名』是否为档案 (file)？ (常用 ) -d 该『文件名』是否为目录 (directory)？ (常用 ) -b 该『文件名』是否为一个 block device 装置？ -c 该『文件名』是否为一个 character device 装置？ -S 该『档名』是否为一个 Socket 档案？  -p 该『档名』是否为一个 FIFO (pipe) 档案？  
-L 该『档名』是否为一个连结档？  2. 关于档案的权限侦测，如 test -r filename  -r 侦测该文件名是否具有『可读』的属性？  -w 侦测该档名是否具有『可写』的属性？  -x 侦测该档名是否具有『可执行』的属性？  -u 侦测该文件名是否具有『 SUID』的属性？  -g 侦测该文件名是否具有『 SGID』的属性？  -k 侦测该文件名是否具有『 Sticky bit』的属性？  -s 侦测该档名是否为『非空白档案』？  3. 两个档案之间的比较，如： test file1 -nt file2  -nt (newer than)判断 file1 是否比 file2 新  -ot (older than)判断 file1 是否比 file2 旧  -ef 判断 file2 与 file2 是否为同一档案，可用在判断 hard link 的判定上。 主要意义在判定，两个档案是否均指向同一个 inode 哩！  4. 关于两个整数之间的判定，例如 test n1 -eq n2  -eq 两数值相等 (equal) -ne 两数值不等 (not equal) -gt n1 大于 n2 (greater than) -lt n1 小于 n2 (less than) -ge n1 大于等于 n2 (greater than or equal) -le n1 小于等于 n2 (less than or equal) 5. 判定字符串的数据   test -z string 判定字符串是否为 0 ？若 string 为空字符串，则为 true test -n string 判定字符串是否非为 0 ？若 string 为空字符串，则为 false。 注： -n 亦可省略  test str1 = str2 判定 str1 是否等于 str2 ，若相等，则回传 true test str1 != str2 判定 str1 是否不等于 str2 ，若相等，则回传 false 6. 多重条件判定，例如： test -r filename -a -x filename  -a (and)两状况同时成立！例如 test -r file -a -x file ，则 file 同时具有 r 与 x 权限时，才回传 true。  -o (or)两状况任何一个成立！例如 test -r file -o -x file ，则file 具有 r 或 x 权限时，就可回传 true。  ! 反相状态，如 test ! -x file ，当 file 不具有 x 时，回传 true 
 

判断符号 [ ] 
最好要注意： 
• 在中括号 [] 内的每个组件都需要有空格键来分隔；    
 
[□ "$HOME" □== □"$MAIL" □] 
• 在中括号内的变量，最好都以双引号来设定；  
• 在中括号内的常数，最好都以单或双引号来设定。  
 
 
 
Find in current folder only, without of recursive: 
     find . -iname 'xPresso*' -maxdepth 1
     ls -d filename
 
 
 
if [ 条件判断式 ]; then  当条件判断式成立时，可以进行的指令工作内容；  elif []; thenelsefi 
 
 
 
test 指令
测试的标志  代表意义  
1. 关于某个档名的『类型』侦测 (存在与否 )，如 test -e filename  -e 该『档名』是否存在？ (常用 ) -f 该『档名』是否为档案 (file)？ (常用 ) -d 该『文件名』是否为目录 (directory)？ (常用 ) -b 该『文件名』是否为一个 block device 装置？ -c 该『文件名』是否为一个 character device 装置？ -S 该『档名』是否为一个 Socket 档案？  -p 该『档名』是否为一个 FIFO (pipe) 档案？  
-L 该『档名』是否为一个连结档？  2. 关于档案的权限侦测，如 test -r filename  -r 侦测该文件名是否具有『可读』的属性？  -w 侦测该档名是否具有『可写』的属性？  -x 侦测该档名是否具有『可执行』的属性？  -u 侦测该文件名是否具有『 SUID』的属性？  -g 侦测该文件名是否具有『 SGID』的属性？  -k 侦测该文件名是否具有『 Sticky bit』的属性？  -s 侦测该档名是否为『非空白档案』？  3. 两个档案之间的比较，如： test file1 -nt file2  -nt (newer than)判断 file1 是否比 file2 新  -ot (older than)判断 file1 是否比 file2 旧  -ef 判断 file2 与 file2 是否为同一档案，可用在判断 hard link 的判定上。 主要意义在判定，两个档案是否均指向同一个 inode 哩！  4. 关于两个整数之间的判定，例如 test n1 -eq n2  -eq 两数值相等 (equal) -ne 两数值不等 (not equal) -gt n1 大于 n2 (greater than) -lt n1 小于 n2 (less than) -ge n1 大于等于 n2 (greater than or equal) -le n1 小于等于 n2 (less than or equal) 5. 判定字符串的数据   test -z string 判定字符串是否为 0 ？若 string 为空字符串，则为 true test -n string 判定字符串是否非为 0 ？若 string 为空字符串，则为 false。 注： -n 亦可省略  test str1 = str2 判定 str1 是否等于 str2 ，若相等，则回传 true test str1 != str2 判定 str1 是否不等于 str2 ，若相等，则回传 false 6. 多重条件判定，例如： test -r filename -a -x filename  -a (and)两状况同时成立！例如 test -r file -a -x file ，则 file 同时具有 r 与 x 权限时，才回传 true。  -o (or)两状况任何一个成立！例如 test -r file -o -x file ，则file 具有 r 或 x 权限时，就可回传 true。  ! 反相状态，如 test ! -x file ，当 file 不具有 x 时，回传 true 
 
 
 
case ..... esac 
 
case $变量名称 in "第一个变量内容 ") 程序段  ;; "第二个变量内容 ") 程序段  ;; *) 不包含第一个变量内容与第二个变量内容的其它程序执行段  exit 1 ;; esac 
 
 
 
function 
function fname() { 程序段  } 
 
 
while [ condition ] do 程序段落  done 
 
until [ condition ] do 程序段落  done 
 
 
for (( 初始值 ; 限制值 ; 执行步阶 )) do 程序段  done 
 
 
 
 
Debug:
[root@linux ~]# sh [-nvx]  scripts.sh 参数：  -n ：不要执行 script，仅查询语法的问题；  -v ：再执行 sccript 前，先将 scripts 的内容输出到屏幕上；  -x ：将使用到的 script 内容显示到屏幕上，这是很有用的参数！  
 
 
  
Linux user and account
 
 
uname - print operating system name
 
 
useradd  usermod   userdel 
passwd - change password
chsh chfn 
 
finger - user info
id - user/group info
 
groupadd groupmod groupdel gpasswd
 
 
su 有一个很严重的问题， 那就是 .....我们必须要知道想要变成的那个人的登入密码
sudo 是怎样工作的呢？  
• 当使用者执行 sudo 时，系统会主动的去寻找 /etc/sudoers 档案，判断该使用者是否有执行 sudo 的权限；  
• 若使用者具有可执行 sudo 的权限后，便让使用者『输入使用者自己的密码』来确认；  
• 若密码输入成功，便开始进行 sudo 后续接的指令；  
• 不过， root 执行 sudo 时，不需要输入密码；  
• 若欲切换的身份与执行者身份相同，那也不需要输入密码。  
  
使用者对谈： talk, mesg, wall, write
 查询使用者： w, who, last, last log 
 
mail
 h  -  list the title
d  -  delete, e.g. d10, d10-20 , but it needs to be used together with [q] to make it take effect
s   -  save as, e.g. s 10 ~/mail.file
q     - quit, and move read mail to ~/mbox, move the mails deleted out of the mailbox.
 x/exit - exit the mail box and do noting, all read/deleted mails will still be in mail box.
 
 
Linux 磁盘配额 (Quota)
……
 
 
例行性命令
 
 
• at ： 这个工作仅执行一次就从 Linux 系统中的排程中取消；  
 
 atp - query current at jobs
 atrm - remove one at job
 
 
• cron/crontab ： 这个工作将持续例行性的作下去！
 
 
 
程序与资源管理 
 
观察目前的背景工作状态： jobs 
将『目前』的工作丢到背景中『暂停』： [ctrl]-z 
将背景工作拿到前景来处理： fg 
管理背景当中的工作： kill     e.g. 
kill -9 %1 
 
 
查阅系统上面正在运作当中的程序 : 静态的 ps 或者是动态的 top
来查阅程序树之间的关系 : pstree 
 
stop process : kill
 
系统相关信息: uname
 
How long since start: uptime
show net status: netstat


Vim Diff Mode:
in console:
$vimdiff file1 file2 [file3 [file4]]
This is equivalent to:$vim -d file1 file2 [file3 [file4]]
in vim:
:diffsplit {filename}

------------------------------------------


Executing External Commands
PROBLEM
You want to run a program from within Vim, possibly having it operate on the current file.
For example, you want to view a list of the other files in your project by getting a listing of the current directory. Or you want to find mistakes in the essay you're working on by passing its filename to the diction utility.
SOLUTION
Invoke the program using the :!program syntax. For example, to view a directory listing on a POSIX system: :!ls.
If you need to pass the current filename to the command as an argument, use the % wildcard. For example, executing :!wc % from aristotle-essay.txt executes wc aristotle-essay.txt.
Filename Modifiers
You can alter the filename represented by % by following the wildcard with a modifier. For example:
%:p
Makes the filename a full path.
%:.
Makes the filename relative to the current directory.
%:t
Removes any directories before the actual file name. For example ~/work/foo.txt  ⇒ foo.txt.
%:e
Removes everything except the filename extension. For example ~/work/foo.txt  ⇒ txt.
DISCUSSION
The concept is that Vim suspends itself, asks your system to execute the command, shows you its output, then, once the user presses <Enter>, returns you to Vim.
If you don't want to see the output of the command, you can execute it like this: :silent  command. (To also hide any error output: :silent! command).
You can use :redir > file if you want to save the output of a command to a file. You first execute, say, :redir > /tmp/output, then :!command. The output for command will be saved in the file /tmp/output, and displayed on the screen. (You can combine :silent command  and :redir file to redirect a command's output to a file without seeing it on screen). To stop output redirection execute :redir END.
You can use :r!command to execute  command and read in its output to the current file. For example, if you're using a POSIX system, you can insert your kernel version with :r!uname -v.
----------------------------------------------------
tarball:
 
套件的内容大致上是摆在 etc, lib, bin, man 等目录当中，分别代表『设定档、函式库、执
行档、在线说明档』

未来的反安装步骤，最好可以将每个套件单独的安装在 /usr/local 底下
加上 man path. 在 /etc/man.config 里面加入：MANPATH /usr/local/rp-pppoe/man 


tarball 软件之安装的指令下达方式： 1.  ./configure    2.  make clean   3.  make   4.  make install 

 

--------------------------
Static library: extension is XXX.a
Dynamic library: extension is XXX.so

most libraries are located in /bin and /usr/bin, libraries of kernel is in /bin/modules


------------------------
ldconfig and /etc/ld.so.conf
load the libraries into cache
 
ldd - list the functions in executable binary file
 
md5sum - validate the software
 
 
---------ignored--------------
xinetd ； TCP_Wrappers


-----------------------
netstat


----------------------
Linux start up order : 

1.  BIOS  
2.  MBR (boot loader)  
3.  kernel loading  
4.  init program  
5.  initial script (/etc/rc.d/rc.sysinit)  
6.  daemon start (/etc/rc.d/rc[0-6].d/*)  
7.  local setting (/etc/rc.d/rc.local)



--------------------------
常用登录相关的 log : 
•   /var/log/secure：  
记录登入系统存取数据的档案，例如 pop3, ssh, telnet, ftp 等都会记录在此档案中；  
•   /var/log/wtmp：  
记录登入者的讯息数据，由于本档案已经被编码过，所以必须使用 last 这个指令来取出档案的
内容； 
•   /var/log/messages：  
这个档案相当的重要，几乎系统发生的错误讯息（或者是重要的信息）都会记录在这个档案中；  
•   /var/log/boot.log：  
记录开机或者是一些服务启动的时候，所显示的启动或关闭讯息；  
•   /var/log/maillog 或 /var/log/mail/*： 
纪录邮件存取或往来( sendmail 与 pop3 )的使用者记录；  
•   /var/log/cron：  
这个是用来记录 crontab 这个例行性服务的内容的！  
•   /var/log/httpd, /var/log/news, /var/log/mysqld.log, /var/log/samba, 
/var/log/procmail.log：  


dmsg, last , lastlog - system log analyzation

ldconfig and /etc/ld.so.conf
load the libraries into cache
 
ldd - list the functions in executable binary file
 
md5sum - validate the software
 

& - execute a command in background, and immediately get the shell back.
    e.g. $ find / -name 'name' > /result


======Backup folder======
•   /boot  
•   /etc  
•   /home  
•   /root  
•   /usr/local(或者是 /opt 及 /srv 等 )  
•   /var(注：这个目录当中有些暂存目录则可以不备份！ )

------------no need to backup-----------------
/dev ：这个随便你要不要备份  
•   /proc：这个真的不需要备份啦！  
•   /mnt ：根据版本不同，有的是 /media 如果你没有在这个目录内放置你自己系统的东西，也不需
要备份  

•   /tmp ：干嘛存暂存档！不需要备份！
-----------------------------
& - execute a command in background, and immediately get the shell back.
    e.g. $ find / -name 'name' > /result.txt
 
 
Kernel compiling and installation
Download kernel soure from www.kernel.org
$cd /usr/src/linux-2.6.xx/
$make mrproper   // remove old .o files
make sure make, gcc have been installed on the system
$make menuconfig
$make clean
$make bzImage   // time consuming
$make modules
if same version kernel compiled two times, rename the /lib/modules/kernelversion first before compile.
$make modules_install
after the successfully compiling, kernel files are in /usr/src/linux-2.6.xx/arch/i386/boot/bzImage

 ---------------------------------------------------------
System boot process:
    Load BIOS(Basic input/output system), and find the 1st device no.
    
    
set the text/background color of echo:
    attribute:  00-none 01-bold 04-underscore 05-blink 07-reverse 08-concealed
    text color:  30-black 31-red 32-green 33-yellow 34-blue 35-magenta 36-cyan 37-white
    background color: 40-black 41-ret 42-green 43-yellow 44-blue 45-magenta 46-cyan 46-white
    format: echo -e "\e[attribute_code;text_color;background_colorm Text_content"

    $echo -e "\e[1;31m This is red text \e[0m"
    $echo -e "\e[1;41m This is text in red background \e[0m"

-------------------------Linux Version ------------------
Distribution versiona: LSB - linux standard base
    1. cat /etc/issue
    2. lsb_release -a
    3. cat /etc/lsb-release
    4. cat /etc/motd

Kernel version:
    1. cat /proc/version
    2. uname -a
    3. uname -m      // i686 => 32bit   x86_64 => 64bit
    4. getconf LONG_BIT  // return 32 or 64

Get cup info:
    cat /proc/cpuinfo

-------------------------
Wildcards in Unix/Linux:
    ?     any single character, except a leading dot
    *     zero or more characters, except a leading dot
    [ ]   defines a class of characters ( - for range, ! to exclude)
    
----------------------------
Regular expression:

^ (Caret) = match expression at the start of a line, as in ^A.
$ (Question) = match expression at the end of a line, as in A$.
\ (Back Slash) = turn off the special meaning of the next character, as in \^.
[ ] (Brackets) = match any one of the enclosed characters, as in [aeiou]. Use Hyphen "-" for a range, as in [0-9].
[^ ] = match any one character except those enclosed in [ ], as in [^0-9].
. (Period) = match a single character of any value, except end of line.
* (Asterisk) = match zero or more of the preceding character or expression.
\{x,y\} = match x to y occurrences of the preceding.
\{x\} = match exactly x occurrences of the preceding.
\{x,\} = match x or more occurrences of the preceding.
   ------------------------------------------------------
umask:
    /etc/profile or ~/.bashrc
    
Octal value : Permission
0 : read, write and execute
1 : read and write
2 : read and execute
3 : read only
4 : write and execute
5 : write only
6 : execute only
7 : no permissions

    e.g. umask=022

or

r : read
w : write
x : execute
u : User ownership (user who owns the file)
g : group ownership (the permissions granted to other users who are members of the file's group)
o : other ownership (the permissions granted to users that are in neither of the two preceding categories)


    e.g. umask u=rwx,g=,o=
    
-----------------LastSaved--------------

find:
    -atime -7 - access time in last 7 days
    -mtime 7 - content modified at the day 7days ago, that day only
    -ctime +7 - attribute changed time, before 7 days
    -a/m/cmin

   -newer
    -size
    -type
    -regex 
    -prune : $ find . \(-name "*.log" -prune\) -o \( type -f -print\) # ignore the files *.log
----------------------------------------------------
-----------------LastSaved--------------
mount -o loop loopback.iso /mnt/iso

cat /source/ > target.iso
dd if=/source of=target.iso

mkisofs -V "label" image.iso source/
cdrecord -v dev=/dev/cdrom image.iso

-------Text browser in Linux---------
w3m
elinks
lynx
----------last saved-----------------

list all installed tools/programs:
    Aptitude-based(Ubuntu/Debian) : dpkg -l     /   dpkg --get-selections
    PRM-based (Fedora, RHEL) : rpm -qa
    pkg*-based (OpenBSD, FreeBSD) : pkg_info
    
------------------------------------

page 698
 
 
 
 
 