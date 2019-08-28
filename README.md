# <a href="https://ibb.co/n0F13LS"><img src="https://i.ibb.co/PYdWT68/Sin-ti-tulo-1.png" alt="Sin-ti-tulo-1" width="100" height="80" border="0"></a> Simple shell

<a href="https://holbertonschool.com"><img src="https://i.ibb.co/RyBcXY6/cherry72.png" align="right" width="200" height="200" alt="cherry72" border="0"></a>
A simple UNIX command interpreter that provides a user interface to access and give orders to the operating system.
## Table of contents
* [Requirements](#requirements)
* [Instalation](#instalation)
* [Compilation](#compilation)
* [Written in](#written-in)
* [Example of use](#example-of-use)
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
* Run an executable:
```sh
$ /bin/pwd
```
* Run an executable founded in the $PATH environment variable:
```sh
$ pwd
```
* Run a shell built-in:
```sh
$ env
```
All commands and builtins that you can use are in the manual page.
## Files and functions
* [main.c](main.c) - File where all the main functions are called
<a href="https://ibb.co/fM78LFT"><img src="https://i.ibb.co/gyCvh9c/Flowchart-shell-copia.jpg" alt="Flowchart-shell-copia" align="middle" border="0"></a>

* [prompt.c](prompt.c) - File where are the main functions to display the prompt
  * `read_line` - print the line
  * `parsing_line` - tokenize and analyze the argument
  * `exec_process ` - execution of process
* [path.c](path.c) - program header file
  * `path_av` - communicate the route with the command
  * `ph_to_dp` - function to put te path route into a double pointer
  * `number_of_dir` - number of directories in the route of path
* [builtin.c](builtin.c) - Builtin functions
  * `_enviro` - function that prints the environmental variables
  * `salto_linea` - Auxiliar function for the use of the command signal
* [own_func.c](own_func.c) - helper functions for the builtins
  * `_strcmp` - compare two strings
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
