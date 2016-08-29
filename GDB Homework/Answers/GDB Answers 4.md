# GDB Homework - Answers to Part 4

In this exercise, you will implement a *lfsr_calculate()* function to compute the next iteration of a linear feedback shift register (LFSR). Applications that use LFSRs are: Digital TV, CDMA cellphones, Ethernet, USB 3.0, and more! This function will generate pseudo-random numbers using bitwise operators. For some more background, read the [Wikipedia article on Linear feedback shift registers](https://en.wikipedia.org/wiki/Linear-feedback_shift_register). In *lfsr.c*, fill in the function *lfsr_calculate()* so that it does the following:

**Hardware diagram (see explanation below)**

![LFSR Diagram](../LFSR-F16.gif)

**Explanation of the above diagram**

  * On each call to *lfsr_calculate()*, you will shift the contents of the register 1 bit to the right.
  * This shift is neither a logical shift or an arithmetic shift. On the left side, you will shift in a single bit equal to the Exclusive Or (XOR) of the bits originally in position 11, 13, 14, and 16.
  * The curved head-light shaped object is an XOR, which takes two inputs (a, b) and outputs a^b.
  * If you implemented *lfsr_calculate()* correctly, it should output all 65535 positive 16-bit integers before cycling back to the starting number.

After you have correctly implemented *lfsr_calculate()*, compile *lfsr.c* and run it. Your output should be similar to the following:

  ```bash
$ gcc -g -o lfsr lfsr.c
$ ./lfsr
My number is: 1
My number is: 5185
My number is: 38801
My number is: 52819
My number is: 21116
My number is: 54726
My number is: 26552
My number is: 46916
My number is: 41728
My number is: 26004
My number is: 62850
My number is: 40625
My number is: 647
My number is: 12837
My number is: 7043
My number is: 26003
My number is: 35845
My number is: 61398
My number is: 42863
My number is: 57133
My number is: 59156
My number is: 13312
My number is: 16285
 ... etc etc ...
Got 65535 numbers before cycling!
Congratulations! It works!
  ```

  __Answer:__
  ```c
  void lfsr_calculate(uint16_t *reg) {

    uint16_t b11 = (*reg >> (16 - 11)) & 1;
    uint16_t b13 = (*reg >> (16 - 13)) & 1;
    uint16_t b14 = (*reg >> (16 - 14)) & 1;
    uint16_t b16 = (*reg >> (16 - 16)) & 1;
    uint16_t msb = (b11 ^ (b13 ^ (b14 ^ b16)));
    msb <<= 15;
    *reg >>= 1;
    *reg |= msb;
  }
  ```
