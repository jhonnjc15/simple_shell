# "0x16. C - Simple Shell" Project.
---
## Description
* Write a simple UNIX command interpreter.

## Files
---
File|Task
---|---
AUTHORS | File with all the people who have contributed to the content of the repository. 
counter_commands.c |
doub_pointer_comm.c |
error_msg.c |
exec_path_direct.c | 
free_double_pointer.c |
get_enviro.c |
help_funct_strings.c |
main.c |
man_1_simple_shell |
print_enviro.c |
README.md |
shell.h |
signal.c |

Directory Name | Description
---|---
simple_shell | Write a simple UNIX command interpreter

## Environment
* Language: C
* OS: Ubuntu 14.04 LTS
* Compiler: gcc 4.8.4
* Style guidelines: [Betty style](https://github.com/holbertonschool/Betty/wiki)

## How to install, compile and use
Install and Compile

```
$ git clone https://github.com/jhonnjc15/simple_shell.git
$ cd simple_shell
$ gcc -Wall -Werror -Wextra -pedantic -Wno-format *.c -o simple_shell
```

**Non-Interactive Mode**
```
$ echo "pwd" | ./simple_shell
/home/pgomez/simple_shell
```

**Interactive Mode**
```
$ ./simple_shell
$ ls -lrth
total 192K
-rw-rw-r-- 1 pgomez pgomez  201 Apr  3 14:32 AUTHORS
-rw-rw-r-- 1 pgomez pgomez  194 Apr  7 23:42 signal.c
-rw-rw-r-- 1 pgomez pgomez  939 Apr  7 23:42 shell.h
-rw-rw-r-- 1 pgomez pgomez  369 Apr  7 23:42 print_enviro.c
-rw-rw-r-- 1 pgomez pgomez  862 Apr  7 23:42 man_1_simple_shell
-rw-rw-r-- 1 pgomez pgomez 2.4K Apr  7 23:42 main.c
-rw-rw-r-- 1 pgomez pgomez  917 Apr  7 23:42 help_funct_strings.c
-rw-rw-r-- 1 pgomez pgomez 2.3K Apr  7 23:42 get_enviro.c
-rw-rw-r-- 1 pgomez pgomez  348 Apr  7 23:42 free_double_pointer.c
-rw-rw-r-- 1 pgomez pgomez  839 Apr  7 23:42 exec_path_direct.c
-rw-rw-r-- 1 pgomez pgomez  359 Apr  7 23:42 error_msg.c
-rw-rw-r-- 1 pgomez pgomez  891 Apr  7 23:42 doub_pointer_comm.c
-rw-rw-r-- 1 pgomez pgomez  504 Apr  7 23:42 counter_commands.c
-rw-rw-r-- 1 pgomez pgomez 1.7K Apr  8 00:34 README.md
-rwxrwxr-x 1 pgomez pgomez  14K Apr  8 00:34 simple_shell
$
```
Opens our manpage for more information
$ ./man_1_simple_shell
$ man 1 simple_shell
$
```

Stop and return to your original shell
```
$ exit 
pgomez@ubuntu14:~/simple_shell$
```

## Bugs
At this time, there are no known bugs.

## More Info
All files are formatted according to Betty style, checked with betty-style.pl and betty-doc.pl
All header files are protected

## Authors
--
Jhonatan Jauja | [GitHub](https://github.com/jhonnjc15)
--
Piero Gomez | [GitHub](https://github.com/pgomezboza)
--