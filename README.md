<a href="https://holbertonschool.com"><img src="https://i.ibb.co/RyBcXY6/cherry72.png" align="right" width="200" height="200" alt="cherry72" border="0"></a>
A simple UNIX command interpreter.
## Table of contents
* [Requirements](#requirements)
* [Instalation](#instalation)
* [Compilation](#compilation)
* [Written in](#written-in)
* [Flow chart](#flow-chart)
* [Files and functions](#files-and-functions)
* [Authors](#authors)
## Requirements
* Ubuntu 14.04 LTS
* gcc version 4.8.4
## Instalation
*  Clone this repository:
```sh
git clone https://github.com/Doniben/simple_shell.git
```
* Inside the repository, compile.
* Execute:
```sh
./hsh
```
* Or run in non-interactive mode, in this mode:
```sh
echo "ls" | ./hsh
```
## Compilation
```sh
gcc -Wall -Werror -Wextra -pedantic *.c -o hsh
```
## Written in
* GNU Emacs 24.3.1
* C language
## Flow chart
## Files and functions
* [AUTHORS](AUTHORS) - List of contributors to this repository
* [man_1_simple_shell](man_1_simple_shell) - Manual page for the simple_shell
* [shell.h](shell.h) - program header file
* [builtins.c](builtins.c) - major builtin functions
  * `check_for_builtins` - checks to see if the user's command matches a builtin
  * `new_exit` - exits the shell with the option of a specified status
  * `_env` - prints the shell's environment variables to the standard output
  * `new_setenv` - initializes a new environment variable, or modifies an existing one
  * `new_unsetenv` - removes an environment variable
* [builtins2.c](builtins2.c) - helper functions for the builtins
  * `add_key` - creates a new environment variable
  * `find_key` - finds an environment variable in the environment array
  * `add_value` - creates a new environment variable string
  * `_atoi` - converts a string into a non-negative integer
* [environment.c](environment.c) - functions related to the environment
  * `make_env` - creates the shell's environment from the parent process
  * `free_env` - frees the shell's environment
* [errors.c](errors.c) - functions related to printing errors
  * `print_error` - prints an error message to the standard error
  * `_puts2` - prints a string to the standard error
  * `_uitoa` - converts an unsigned integer to a string
* [memory_allocation.c](memory_allocation.c) - memory allocation functions
  * `_realloc` - a custom realloc function for arrays of pointers
* [new_strtok.c](new_strtok.c) - custom strtok and helper functions
  * `check_match` - checks if a character matches any in a string
  * `new_strtok` - a custom strtok for the shell
* [path.c](path.c) - functions related to executing commands
  * `path_execute` - executes a command in the PATH
  * `find_path` - finds the PATH environment variable
  * `check_for_path` - checks if the command is in the PATH
  * `execute_cwd` - executes a command with an absolute path
  * `check_for_dir` - checks if the command contains an absolute path
* [simple_shell.c](simple_shell.c) - essential functions to the shell
  * `main` - the main function of the program
  * `sig_handler` - handles SIGINT
* [strfunc.c](strfunc.c) - functions related to string manipulation
  * `_puts` - writes a string to standart output
  * `_strdup` - duplicates a string
  * `_strcmpr` - compares two strings
  * `_strcat` - concatenates two strings with a `/` in the middle
  * `_strlen` - calculates the length of a string
* [tokenize.c](tokenize.c) - tokenizing function
  * `tokenize` - creates an array of tokens from a buffer with a specified delimiter
### Authors
 - [Doniben Jimenez](https://github.com/Doniben)
 - [Nicolás Morán](https://github.com/nickmoran06)
