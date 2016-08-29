# CS 173 - Homework on Valgrind

Adapted from:
* https://courses.cs.washington.edu/courses/cse333/12su/sections/section2.pdf
* https://wr.informatik.uni-hamburg.de/_media/teaching/sommersemester_2014/cgk-14-menck-memory-leaks-exercises.pdf 

## Things to Remember

* Compile c99/c11 code by adding the ```-std``` option in gcc.
* Provide symbol table information to valgrind by adding the ```-g``` option in gcc.
* Use the option ```--leak-check=full``` and ```--show-reachable=yes``` to output m
ore details from Valgrind.

## I. Memcheck

Consider the following C files:

* *ex1a.c*
* *ex1b.c*
* *ex1c.c*

For each file, do the following:

1. Compile the code.
2. Use Memcheck to see the error.
3. Correct the error so that Memcheck will no longer give an error message.

__Deliverables:__
1. The corrected source files, with comments that describe the errors found by Memcheck and the modifications that are required to fix the error.
  * There could be  more than 1 error on each program.
  * There are many ways to fix an error. As long as Memcheck will no longer give an error message, the fix can be considered valid (only for this homework).

## II. Vector

Consider the expandable vector code in *vector.c*:
1. Try to find all the bugs by inspection.
2. Use Valgrind on the same code. What are the errors?
3. Fix all the errors found by Valgrind.

__Deliverables:__
1. The corrected version of *vector.c*, with comments that describe the errors found by Memcheck and the modifications that are required to fix the error.
