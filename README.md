# Simple Shell Project in C

This is a simple shell program written in C that mimics the basic  functionality of the Unix shell.

## Getting Started

These instructions will get you a copy of the project up and running on your local machine for development and testing purposes.

### Prerequisites

To run this program, you will need a C compiler such as gcc.

### Installing

Clone the repository to your local machine:

```
git clone https://github.com/abdallahfarag72/simple_shell.git
```

Compile the program using gcc:

```
gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c -o hsh
```

Run the program:

```
./hsh
```

## Usage

Once the program is running, it will display a prompt indicating that it is ready to accept commands:

```
$
```

The shell supports the following commands:

- `cd`: change directory
- `pwd`: print working directory
- `exit`: exit the shell

In addition, the shell can run any command that can be executed from the command line.

## Example

```
$ pwd
/home/username/simple-shell
$ ls
README.md shell.c
$ cd ..
$ pwd
/home/username
$ exit
```

## Authors

* **Michael Slippe** - [Ahnyspecter](https://github.com/Ahnyspecter)
* **Abdallah Azzam** - [abdallahfarag72](https://github.com/abdallahfarag72)
