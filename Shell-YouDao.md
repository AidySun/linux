# Shell-YouDao


- disk usage
  du -sh [path]



!$ - the last string in the last command.
$? - the return value of last comman

ALT+./ESC+. - the parameters in the last command

^old^new - replace the 'old' with 'new' in last command
it also can be !!:s/old/new


echo:
    1. following strings directlly, will caculate the environment variable, stop at sign ;
        e.g. echo hello $USER -> hello CurrentUserName
             echo hello; $USER -> hello
    2. string with single qoute, treat content as plain text
        e.g. echo 'hello; $USER' -> hello; $USER
    3. string with double qouters, caculate the environment variables, treat semi-collon as text 
        e.g. echo "hello; $USER" -> hello; CurrentUserName


set the text/background color of echo:
    attribute:  00-none 01-bold 04-underscore 05-blink 07-reverse 08-concealed
    text color:  30-black 31-red 32-green 33-yellow 34-blue 35-magenta 36-cyan 37-white
    background color: 40-black 41-ret 42-green 43-yellow 44-blue 45-magenta 46-cyan 46-white
    format: echo -e "\e[attribute_code;text_color;background_colorm Text_content"

    $echo -e "\e[1;31m This is red text \e[0m"
    $echo -e "\e[1;41m This is text in red background \e[0m"



!$ - the last string in the last command.
$? - the return value of last command

ALT+./ESC+. - the parameters in the last command

^old^new - replace the 'old' with 'new' in last command
it also can be !!:gs/old/new

get the length of the variable:
    length=${#var}

the uid of root user is 0.

------------------------
Arithmetic in shell: [INTEGER]
    1. let
       i=3;
       j=5;
       let result=i+j;
       echo $result

    2. $(())
        result=$((i+j));
        echo "i+j=$result"

    3. $[]
        result=$[i+j];


    
    4. exprt
        result=`expr i+j`
        result=$(expr $i+10)
       
[FLOAT]
    result=`echo 3.14*3 | bc`
    echo $result
----------------------
bc
    $echo "scale=2; 3/7 | bc 
    ibase=10
    obase=2
    scale=3 
----------------------
Output in Shell:
    1. echo
        
set the text/background color of echo:
   attribute:  00-none 01-bold 04-underscore 05-blink 07-reverse 08-concealed
   text color:  30-black 31-red 32-green 33-yellow 34-blue 35-magenta 36-cyan 37-white
   background color: 40-black 41-ret 42-green 43-yellow 44-blue 45-magenta 46-cyan 46-white
   format: echo -e "\e[attribute_code;text_color;background_colorm Text_content"

    $echo -e "\e[1;31m This is red text \e[0m"
    $echo -e "\e[1;41m This is text in red background \e[0m"

    2. printf
        printf "i=%d j=%d i+j=%d" $i $j $result;

----------------------
I/O
    0 - stdin
    1 - stdout
    2 - stderr

------------------------
===============Command line tricks===============
$ cp ./main.cpp{,-bak}
    it will be expands to :
    $ cp ./main.cpp ./main.cpp-bak

!^, !$, !*
1st non-cmd item, last non-cmd item, all non-cmd items
    $ echo item1 item2 item3
    !^ = item1   
    !$ = item3
    !* = item1 item2 item3

reload .bashrc without logout
    $ source ~/.bashrc

-----------------------------
Wildcards in Unix/Linux:
    ?     any single character, except a leading dot
    *     zero or more characters, except a leading dot
    [ ]   defines a class of characters ( - for range, ! to exclude)
----------------------------
Regular expression:

^ (Caret)=match expression at the start of a line, as in ^A.
$ (Question)=match expression at the end of a line, as in A$.
\ (Back Slash)=turn off the special meaning of the next character, as in \^.
[ ] (Brackets)=match any one of the enclosed characters, as in [aeiou]. Use Hyphen "-" for a range, as in [0-9].
[^ ]=match any one character except those enclosed in [ ], as in [^0-9].
. (Period)=match a single character of any value, except end of line.
* (Asterisk)=match zero or more of the preceding character or expression.
\{x,y\}=match x to y occurrences of the preceding.
\{x\}=match exactly x occurrences of the preceding.
\{x,\}=match x or more occurrences of the preceding.
    
--------------------
smbmount //win/share -o username=name,domain=do /mnt/share

--------------
tee - read from the stdin only (except stderr), output to file and stdout.

----------
Here document << [-]word
    read until the line with 'word'.
    [-] will trip blanks 

exec - redirection, < for read, > for write, >> for append write
    $exec 4>out.txt # write 4 to out.txt
    $echo new line >4
    $echo out.txt
     new line
    $
-----------------
array
    $array_1=(item1 item2 item3)
    $echo ${#array_1[*]}   # the array length
    $echo ${!array_1[*]}    # the array options, 0 1 2 is the output for this case

association array, since Bash 4.0
    #!/bin/bash
    declare -A array_2
    array_2=([apple]="red" [pear]="yellow")
    echo ${!array_2[@]}    # output apple pear
    echo ${array_2[*]}     # output red yellow
------------------
escape the alias command: /
    e.g. system has a command vi, we can create a new alias with name vi. 
    $echo 'alias vi="ls -l"'
    $vi    # will exec the alias ls -l
    $\vi   # will exec the original exec vi, but not alias

------- saved -----------

tput sc - save the cursor position
tput rc - restore the cursor position to sc
tput ed - clear to the end of screen
tput el - clear to the end of line

------------
parameters in shell funtion:
    $1 ~ $9 - positional parameter
    $$ - current process id 
    $# - parameter number
    $0 - the current shell
    $? - exit code of last command
    $* $@ - the same, all parameters
    "$*" - "$1c$2c$3", c is the first char in IFS
    "$@" - "$1" "$2" "$3", is normal use

---------------
run in sub-shell: use ()
    $out="$(ls | cat -n)"
    $echo $out

-----------------
read:
    read -n num var
    read -p "messages:" var
    read -t sec var
    read -d ":" var
    read -s password

------------------
IFS:
    $echo $IFS
    $IFS=".,:"   # separator will be . or , or :

----------loops---------
1. while [ $a -eq "1" ]; 
    do
    commands;
    done
2. for item in list;
    do
    commands;
    done
3. for((i=1;i<10;i++))
    {
    command;
    }
4. until [ $a -eq "end" ];
    do
    command;
    done

-------------------
find with multi conditions:
    $ find ~/ \( -name '*.txt' -o -name '*.pdf' \) -print

--------------------
xargs:
    $ cat par.txt | xargs -n 2 ./exe.sh
    $ cat par.txt | xargs -I {} ./exe.sh -p {} -l
    $ cat par.txt | (while read par; do echo $par; done)

    $ find . -name *.log -print0 | xargs -0 rm -f # don't forget the -print-0 and -0 in xargs
--------------------
tr - the collections that can be used in tr:
    alnum - all letters and num
    alpha - all letters
    lower - lower case letters
    upper
    digit - num
    cntrl - control letters (not printable)
    graph - praph letters
    print - printable letters
    punct - punctuations
    xdigit - num in hexadecimal
    
e.g. $ cat par.txt | tr '[:digit:]' 'x'

-----------------

uniq:
    -c - count the lines
    -s - ignore how many chars
    -w - compare how many chars
    -d - output the line repeated

sort:
    -k - which column will be used for sorting
    -r - reverse sorting
    -b - ignore the leading blanks


------------------
midir -p /a/b/c - it will ignore the existed folder and create the unexisted ones

--------------

Get file name/extionsion in Shell:
    1. get file name
        file="filename.ext1.ext2"
        long_name=${file%.*}
        short_name=${file%%.*}

        #long_name = filename.ext1
        #short_name = filename

    2. get file extionsion
        long_ext=${file#*.}
        short_ext=${file##*.}

        #long_ext = ext1.ext2
        #short_ext = ext2

%% and ## are greedy.

----------------
comm - compare two sorted file line by line

----------
 chattr +i filename - make the file immutable, cannot modify and remove.

----------
diff file1 file2 > diff.patch
patch file1 < diff.patch

diff -u file1 file2
diff -q file1 file2
------------
tail -n 10
tail -n +10     # output the lines since line 9
head -n 10
head -n -10     # output the lines except last 10 lines

--------
pushd /root/home
dirs
pushd +2
popd +1
note : the path stack index starts from 0

----------------------------
wc -l file      # line num
wc -w file      # word num
wc -c file      # character num

-----sed-------------------------

sed [option] 'SELECTION edit-instructions' file(s)

CONCEPT:
    if has content match SELECTION, read it into pattern space; execute the edit-instruction command to the content in the pattern space; then output the result and clear the pattern space;
    sed has a hold space, which stores the temp result string, never be output.



SELECTION:
    single line - 5: the fifth line; $: the last line
    range line - 4,$: from 4th line to the end
    single regex - /string/: the lines include 'string'
    regexp range - /^on/,/off$/: from the 1st line starts with 'on' to the first line ends with 'off'
    line range with regex - 2,/end/: from line 2 to the line has 'end'
    besides condition - /string/!: the lines don't include 'string'

edit-instructions:
     p - print
     a - append
     i - insert
     c - change
     d - empty the pattern space, immediately start next loop without outputing the pattern space content
     D - delete the content from 1st to 1st \n, if pattern space is not empty, re-execute the command from begining without reading next line
     n/N - read the next line and append to pattern space seperate with \n
     

REPLACE:
    sed s/oldstr/newstr/ - replace the 1st 'oldstr'
    sed s/oldstr/newstr/g - replace all the 'oldstr'
    sed y/oldchars/newchars/ - replace the 'oldchars' to be 'newchars' in the according position, same with command tr

FILE:
    sed 'SELECTION command/w outfile' file - do the command and write the result ONLY (not entire file) to outfile. e.g. sed 's!old!new!gw new.txt' old.txt.
    
    sed '/bellowing content"/r readfile' file - append the 'readfile' content to the 'bellowing content'

BATCH:
    sed -f scriptfile file(s)
    e.g. scriptfile has content:
            s/123/312/
            s/name/Name:/g

    sed -e 's/123/321/' -e 's/name/Name:/g' file(s)
    sed 's/123/321/;s/name/Name:/g' file(s)
    sed 's/123/{s/2/tow
     >   s/3/three
     >   }' file(s)

sed substrings:
  sed -e "s/.*\(get@\|http[s]*\).*/\1/"       #search get@ or http[s]

====e.g.====
1. delete the html tags
    $ sed 's/<[^>]*\>//g' file.html
    NOT $ sed 's/<.*>//g', this will delete all thing between 1st < and last >.

2. output content reservedly
    $ sed '1!G;h;$!d' file.txt

3. output each line twice
    $ sed '1p;N;p;D;p' file.txt

====Label in sed========
:label - specification of label
b label - unconditional label jump, if label not existed, jump to the end of command
t label - conditional label jump, only jump only if the last command substitute modified the pattern space content, if the lable is not existed, jump to the end of the command


e.g.
   1. only replace the 1st appearence in the document
    $ sed '/string/{
        :loop
        N
        b loop
        }s/string/newstr/' file
    
    2. only replace the 2nd appearence in the doc
    $ sed ':loop
        $!{
        N
        b loop}
        s/ is/ IS/2' file

----------------
ifconfig - config a network interface, the modification will be lost after restart the device, because it doesn't change the configuration file of the device.


------------------------------


grep "matched_pattern" files:
 
--color : $grep "matched_pattern" files --color=auto   : auto highlight the matched strings
-E : use the extended regular expression in the "matched_pattern", or egrep command.
-c : output the mattched line numbers instead of the content.
-v : $grep -v "pattern" files, search the content NOT matched the "pattern".
-o : only output the matched content, not the entire line.
-b : output the bytes offset (from begin of input file) of each matched item. always used together with -o.
-n : output the line number.
-l : only output the file names which includ the matched content.
-L : output the file names that DON't include the matched content.
-R/-r : search the content recursive. $ grep "function()" . -R -n
-i : case insensitive.
-e : e.g. $ grep -e "str1" -e "str2" files
-f : read the pattern from file. e.g. $grep -f pattern.txt files
--include : $ grep "main()" -r --include *.{c, cpp} : search the main() in all .c and .cpp files.
--exclude : $ grep "main()" -r --exclude "README" 
-Z : output \0 instead of space between each matched results. usually used with -l.
-A [num] : output the [num] lines after the matched line.
-B [num] : output the [num] lines before the matched line.
-C [num] : output the [num] lines after and before the matched line.    e.g. $ seq 10 | grep 5 -C 3
 
 
 
e.g.
count the matched numbers: $ grep -o -E 'regex' files | wc -l

 
------------------cut---------------------------
cut -f 1,2 file.txt : will output the 1st and 2nd columns of file.txt, by default, it uses tab as the demiliter.
cut -d';' -f 2 file.txt : use ';' as the delimiter
-b : by byte
-c : by char    e.g. $ cut -c1-5 file.txt : will output the characters from 1 to 5 of the file.txt
N : Nth filed/char/byte
N- : from N to the end of line
N-M : from N to M
-M : from start to M
--complement : output the complement(BuJi) of the matched filed/char/byte
--output-delimiter 'n' : use n as the delimiter in the output


----------------------------------------------
substr in shell : 
    ${word:start_pos:num_of_char}   : e.g. $ echo ${variable:10:2}

${#variable} is the length of variable

---------------------------------------
paste : merge files by columns

e.g. paste file1 file2 -d "-"

-----------------------
download files:

wget [URL]
cURL [URL]
lynx [URL] - get the pure text web content
lynx -traversal URL - access all links recursively, and generate many files, including one named reject.dat for those invalid URLs.
----------------------
-------------------------
tar:
    -c : create 
    -x : extract
    -f : specify the archive file
    -t : list the files in archive file
    -v : verbosely list files processed
    -u : only update files have new copy. e.g. $ tar -uvvf a.tar file1
    -d : find differences between archive file and system. e.g. $ tar -df a.tar file
    --delete : remove from archive file. e.g. $ tar -f a.tar --delete file1
    --exclude :  e.g. $ tar -cvf a.tar ./* --eclude "*.csv"
    --exclude-vcs: exclude version control system directories
    --totals : print the file size once finish
    -X : read the excluding files from file.  e.g. $ tar -cvf a.tar ./* -X exclude.txt
    
    -A : merge two archive files. e.g. $ tar -Af 1.tar 2.tar
    -C : specify the output path

    -z : compress the file using gzip.  e.g. $ tar -cvzf archive.tar.gz ./*.cpp
    -a : compress the file according to the file extention
    
Copy files :
    $ tar -cf - file1 file2 | tar -xf - -C /tofolder/
 
-------------------------------
cpio:
    -o : copy out mode
    -i : copy in mode
    -p : copy pass mode. pass/paste the file.   e.g. $ find . -name "*.cpp" -print0 | cpio --null -p /sourcecode/  : will copy *.cpp files to folde sourcecode.
    -t : show the archive content
    -v : print the files be archived
    -d : create the directors necessarily
    -u : force overwrite the existing files
    --null/-0 : read the input parameter with null terminaled, instead of end of new line.


-------------------------------


$ find . -depth : -depth option forces the find command to print the entries in a directory before printing the directory itself.
    $ ./a
      ./b
      .

$ find . -print0 | [somecmd] --null
    -pirnt0 and --null use together to make the files/directories of find result be passed correctly to [comecmd] ever there are special characters in the name of files/directories.
------------------------------
gzip/gunzip:
    can only work only sigle file (not directory and multi files).
    
$ gzip -l file.gz   : list the compressed file info

$ cat filea fileb | gzip > archive.gz
is better than 
$ gzip filea fileb > archive.gz

zcat - show the files in the gzip format file.

---------------------
bzip2/bunzip2:
    the file extension is .bz2

    use -j option in tar to use bzip2 to compress the file.

-----------------
lzma:  anothe newer compress tool on linux

---------------------------
zip/unzip:      it won't remove the original files after the compression, this point is diff from gzip/bzip2/lzma.


------------------------
squashfs:
    $ mksquashfs SOURCES  compressedfs.squashfs
    # mkdir /mnt/squash
    # mount -o loop compressedfs.squashfs /mnt/squash


------------------------------
crypt
gpg - GNU privacy guard
base64
md5sum
sha1sum

md5sum and sha1sum are all <unidirectional hash algorithm>, that means it cannot guess the original value according to the result.

-------------------------------------
rsync - synchronize the data 
    $ rsync -avz source_path destination_path
    $ rsync -avz source_path user@server_name:path       e.g. $ rsync -av /etc aidy@10.32.229.113:/user/xpresso/

-a : archive
-v : list the processing file
-z : compress the file

source_path: if it ends with /, it will only copy the files under source_path to the destiantion path; if it is not ending with /, the source_path itself will be copied to destination as well.

destination_path: if it ends with /, the files under source_path will be copied; else, it will create a new direction under destination_path for source_path.


-----------------------Git---------------------------TODO

// TODO

----------------------------------------
dd - convert and copy a file, it can be used to copy the data between hard disk, CD, DVD, flash memroy and so on. Because it not only copy the files, but also the info like MBR, disk partition.

    if=input_file
    of=output_file
    bs=block_size
    count=block_count 


if count is not set, it will end at EOF. dd also can be used to generate mirror image (.img  .iso). e.g. $ dd if=/dev/ of=dev.img

mount a imge/iso:
    $ mount -o loop dev.img /mnt/dev/
---------------------------------
ifconfig - under /sbin/ifconfig.
 ifconfig - config a network interface, the modification will be lost after restart the device, because it doesn't change the configuration file of the device.   

$ ifconfig eth0 hw ether 00:13:bf:3c:23   -   set another MAC address for eth0
$ route -n      -  show default gateway


set ethernet in Linux:
    $ ifconfig eth0 down
    $ ifconfig eth0 hw ether 00:13:bf:33   - optional
    $ ifconfig eth0 10.32.22.1 netmask 255.255.255.0    - set ip
    $ ifconfig eth0 up
    $ route add default gw 10.32.22.0 eth0      -  set getway

------------------------------
host
traceroute
route


----------------------------
lftp:
    $ lftp user_name@server_host
    lftp :~> get / put [file_name]
    lftp :~> cd  /  ls  / lcd - lcd will change the local path
    lftp :~> quit

similar tools are : ftp, sftp, scp

------------------------------
ssh - shorthand for Secure SHell
        
    $ ssh user_name@host_server  [command1; command2...]

-----------------------------
du - estimate file space usage
df - report the file system disk space usage

--------------------------
time [command] -  caculate the command execution time

-------------------------
who/w
users - current logined users
uptime - the system up time
last - the info about last login
lastb - the login failed info

----------------------------------
watch date &    -  & make the command be executed in background

fg - bring the last background cmd to foreground.
jobs - list the jobs
fg %job_id 

kill -19 %job_id

kill $!   -  $! means the pid of the last cmd executed in background

killall process_name - kill process by name

--------------------------------------------
inotifywait ( inotify-tools) - track the changes of files/folders

logrotate - log tool
logger [MSG] - write log info to syslog


---------------------------------
top
ps -aux --sort -pcpu
pgrep - find the pid of process
----------------------
whatis CMD
whereis CMD
file FILE
which CMD
apropos CMD - find the manual by key word

-------------------
wall - send message to all terminal users

$ cat MESSAGE | wall
$ wall < MESSAGE

$mesg y/n  - enable/disable the message broadcase, but if the message was send by super user, it will always be shown.

-------------------------------
hostname
uname
cat /proc/cpuinfo

cron
-----------------
imagemagick

------------------------
How to indicate which shell is using?
    $ echo $SHELL
    $ echo $0


访问Windows共享目录：
smbclient -U "DOMAIN\user" //dc.domain.com/share/test/dir

Grep whole words:
grep -w "name" test.txt
打印历史记录中最后一次cat命令：
!cat:p



将tabs转换成空格：
expand test.txt > test1.txt
























