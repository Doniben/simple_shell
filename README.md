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
## Example of use
## Files and functions
* [main.c](main.c) - File where all the main functions are called
* [prompt.c](prompt.c) - File where are the main functions to display the prompt
  * `read_line` - print the line
  * `parsing_line` - tokenize and analyze the argument
  * `exec_process ` - execution of process
* [path.c](path.c) - program header file
  * `path_av` - communicate the route with the command
  * `ph_to_dp` - function to put te path route into a double pointer
  * `number_of_dir` - number of directories in the route of path
  * `conc_slash` - function to concatenates each directory with a slash at the end
* [environment.c](environment.c) - environment builtin function
* [own_func.c](own_func.c) - helper functions for the builtins
  * `_strcat` - concat two strings
  * `_strdup` - a function that duplicates a string
  * `_strlen ` - function to return the length of a string
  * `_putchar` - writes the character to stdout 
* [header.c](header.c) - The header file
* [man_1_simple_shell](man_1_simple_shell) - Manual page for the simple_shell
* [AUTHORS](AUTHORS) - List of contributors to this repository
### Authors
 - [Doniben Jimenez](https://github.com/Doniben)
 - [Nicolás Morán](https://github.com/nickmoran06)
