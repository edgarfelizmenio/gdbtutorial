# CS 173 - GDB Exercise 1

Exercise adapted from: https://courses.cs.washington.edu/courses/cse303/04au/Homework/gdb/

## Objectives

For this exercise, the objective is to be able to do the following:

1. Creating core dump files.
  * Core dump files contain the state of the memory of our program the time it crashed.
2. Open gdb in your terminal.
3. Use the following gdb commands:
  * **help <command>** - get documentation on <command>.
  * **core** - display the core dump
  * **bt** - display the stacktrace at the time of the crash.
  * **list <line>** - list ten lines around specified line.
  * **print <exp>** - print value of current expression.  
  * **q** - quit gdb
  * **run** - run the program in gdb. You may pass command-line arguments and/or redirect input/output as if you are running the program in a terminal.
  * **break <line>** - set a breakpoint at <line>. A breakpoint is an intentional pause set in a program for debugging purposes.
  * **step [N]** - step N times
  * **continue** - continue running the program after a breakpoint.
4. Compile the program with the ```-Wall``` option.

## Instructions

Open *gdbExample.c* and do the following:

1. To be able to generate core dump files, enter this command in your terminal:
  ```bash
  ulimit -c unlimited
  ```

2. Compile and run *gdbExample.c*
  ```bash
  gcc -o gdbExample gdbExample.c
  ./gdbExample
  ```
What happened?

3. Open the program using gdb and inspect the core dump.
  ```bash
  gdb gdbExample
  (gdb) core core
  ```
What does the core dump contain?

4. Check which functions are being called when the program crashed:
  ```bash
  (gdb) bt
  ```

5. Try to inspect your code to see where the crash happened.
  ```bash
  (gdb) list
  ```
Was it helpful?

6. Quit gbd for now and delete the core dump.
  ```bash
  (gdb) q
  ```

7. Compile *gdbExample.c* again. This time, use the ```-g``` option.
  ```bash
  gcc -g -o gdbExample gdbExample.c
  ```

8. Repeat step 3. Is there something new?

9. Check the state of the program variables.
  ```bash
  (gdb) print i
  (gdb) print x[10]
  (gdb) print x[i]
  ```

10. Repeat step 5. Was it helpful?

11. Correct your program. Compile it again with the ```-g``` option. Run it again on gdb.
  ```bash
  gcc -o gdbExample gdbExample.c
  gdb gdbExample
  ```

12. Add breakpoints at line 8 and run the program.
  ```bash
  (gdb) break 8
  (gdb) run
  ```

13. Inspect the next functions using the ```step``` command.

14. Enter another breakpoint at line 12 and continue running the program to that breakpoint.
  ```bash
  (gdb) break 12
  (gdb) continue
  ```

15. Continue program execution. What happened?
  ```bash
  (gdb) continue
  ```

16. Correct the program and debug again using gdb.

## Additional Exercises

1. Try compiling gdbExample.c with the ```-Wall``` switch. What does it tell you? Is it useful? surprising?
2. Try writing a program with multiple functions, one of which causes the program to crash. Investigate he usage of ```bt```, ```up```, and ```down``` commands provided by
 gdb.
