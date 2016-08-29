# GDB Homework - Answers to Part 1

0. How do you compile C programs so that it will give useful information to gdb?

  __Answer:__
  ```bash
  gcc -g -o <program_name> <source_code>.c
  ```

1. How do you pass command line arguments to a program when using gdb?

  __Answer:__
  Similar to running programs without gdb.

  For command line arguments:
  ```
  (gdb) run progam_name arg1 arg2 ...
  ```

  For I/O redirection:
  ```
  (gdb) run program_name < input_file > output_file
  ```

2. How do you set a breakpoint which only occurs when a set of conditions is true (e.g. when certain variables are a certain value)?

  __Answer:__
  Use the ```if``` option of the ```break``` command.

  Sample usage - pause _iter.c_ at line 6 if ```i == 5```:
  ```
  (gdb) break iter.c:6 if i == 5
  ```

3. How do you execute the next line of C code in the program after stopping at a breakpoint?

  __Answer:__
  Use the ```next``` command.
  ```
  (gdb) next
  ```

4. If the next line of code is a function call, you'll execute the whole function call at once if you use your answer to #3. How do you tell GDB that you want to debug the code inside the function instead?

  __Answer:__
  Use the ```step``` command.
  ```
  (gdb) step
  ```

5. How do you resume the program after stopping at a breakpoint?

  __Answer:__ Use the ```continue``` command.
  ```
  (gdb) continue
  ```

6. How can you see the value of a variable (or even an expression like 1+2) in gdb?

  __Answer:__ Use the ```print``` command.

  Example usage - print the value of variable ```x```:
  ```
  (gdb) print x
  ```

  Example usage - print the value of expression ```1 + 2```
  ```
  (gdb) print 1 + 2
  ```

7. How do you configure gdb so it prints the value of a variable after every step?

  __Answer:__ For each variable/expression that you want to be printed, use the ```display``` command. A code number will be assigned to the variable/expression.

  Example usage:
  ```
  (gdb) display i
  1: i = 1000
  (gdb) display x[i]
  2: x[i] = 0
  (gdb) display i + x[i]
  3: i + x[i] = 6
  ```

  Use the ```undisplay``` command to stop. The arguments to ```undisplay``` are the code numbers of the expressions to stop displaying.

  Example usage:
  ```
  (gdb) undisplay 3
  (gdb) undisplay 2
  (gdb) undisplay 1
  ```

8. How do you print a list of all variables and their values in the current function?

  __Answer:__ Use the ```info``` command all variables and values:
  * ```info variables``` to print all global and static variable names
  * ```info locals``` to print local variables of current stack frame (or function call)
  * ```info args``` to print arguments of current stack frame (or function call)

9. How do you exit out of gdb?

  __Answer:__ Use the ```quit``` command.
  ```
  (gdb) quit
  ```
