# GDB

## Motivation

## Prerequisites

* Unix Machines are recommended but not required.
* An ANSI-compliant C compiler.
* 115 MB of free disk space for building GDB
* 20 MB of free disk space for installing GDB

## Installation

1. Check if your system has GDB installed:
  ```bash
  gdb -help
  ```
  If GDB is installed, then it will display all the available options within your GDB. If GDB is not installed, then proceed for a fresh installation.

2. Use the following command to install GDB on Linux:
  ```bash
  sudo apt-get install libc6-dbg gdb valgrind
  ```
  Valgrind is not yet required, but we will use it in the next session.

## Usage

### Symbol Tables
A Debugging Symbol Table maps instructions in the compiled binary program to their corresponding variable, function, or line in the source code. This mapping could be something like:

* Program instruction ⇒ item name, item type, original file, line number defined.

Symbol tables may be embedded into the program or stored as a separate file. So if you plan to debug your program, then it is required to create a symbol table which will have the required information to debug the program.

We can infer the following facts about symbol tables:

* A symbol table works for a particular version of the program – if the program changes, a new table must be created.
* Debug builds are often larger and slower than retail (non-debug) builds; debug builds contain the symbol table and other ancillary information.
* If you wish to debug a binary program you did not compile yourself, you must get the symbol tables from the author.

To let GDB be able to read all that information line by line from the symbol table, we need to compile it a bit differently. Normally we compile our programs as:

```bash
gcc hello.cc -o hello
```

Instead of doing this, we need to compile with the ```-g``` flag as shown below:

```bash
gcc -g hello.cc -o hello
```

Note that the ```-g``` option is only available in the GCC compiler. This option enables the use of extra debugging information that only GDB can use.

### Commands

GDB offers a big list of commands, however the following commands are the ones used most frequently:

* **b main** - Puts a breakpoint at the beginning of the program
* **b** - Puts a breakpoint at the current line
* **b N** - Puts a breakpoint at line N
* **b +N** - Puts a breakpoint N lines down from the current line
* **b fn** - Puts a breakpoint at the beginning of function "fn"
* **d N** - Deletes breakpoint number N
* **info break** - list breakpoints
* **r** - Runs the program until a breakpoint or error
* **c** - Continues running the program until the next breakpoint or error
* **f** - Runs until the current function is finished
* **s** - Runs the next line of the program
* **s N** - Runs the next N lines of the program
* **n** - Like s, but it does not step into functions
* **u N** - Runs until you get N lines in front of the current line
* **p var** - Prints the current value of the variable "var"
* **bt** - Prints a stack trace
* **u** - Goes up a level in the stack
* **d** - Goes down a level in the stack
* **q** - Quits gdb

## References

* GDB Prerequisites and Installation:
  * http://www.tutorialspoint.com/gnu_debugger/installing_gdb.htm
* Debugging GCC programs with GDB:
  * http://www.tutorialspoint.com/gnu_debugger/gdb_debugging_symbols.htm
  * http://linux.die.net/man/1/gcc
