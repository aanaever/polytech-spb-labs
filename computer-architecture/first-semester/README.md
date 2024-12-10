# Computer Architecture

This folder contains lab works for the course "Computer Architecture".
## Home Work  
  - Translate a mnemonic instruction into machine code.
  - Translate machine code into Intel and AT&T mnemonics.
  - Perform bit shifts on a given instruction.
  - Convert a decimal number into binary floating-point format.
    
[Solution](homework1.pdf)


## Lab Works
### Lab Work #1 Instruction Set Architecture and Command Codes

[Solution](lab_2_v3/)
#### Task Overview:
1. Arithmetic and Logical Operations:
  - Write and execute the following operations in C using inline assembly: add, inc, sub, cmp, mul, or, not, xor, and, test.
  - Record the command in C, using inline assembly. Then, compile and transition to the Turbo Debugger (TD) to analyze the result.
2. Memory Transfer Using LOOP and LEA Commands:
  - Perform array-to-array data transfer using the LOOP and LEA commands.
3. Memory Transfer Using String Instructions:
  - Write a program to transfer data from one array to another using string instructions (LODS, MOVS, STOS) with the REP prefix and appropriate register preparation.
4. Data Transfer in LARGE Memory Model:
  - Write a program to transfer data between arrays in the LARGE memory model using LDS and LES instructions. Explain how the registers are utilized.
5. Memory Transfer Between Physical Addresses:
  - Write a program using string instructions to transfer data from a memory segment starting at physical address B8000 to a segment starting at B9000. Use a debugger to show how the processor registers change during data transfer and how memory is populated.

### Lab Work #2 Assembly Language and BIOS Functions   
[Solution](lab_1_v3/)
### Task Overview:
1. Write an Assembly Program for Transferring Single-Digit Data
  - Write an Assembly program that transfers single-digit data from one array to another using string instructions. Display the data on the computer screen using BIOS interrupt 21h, function 2.   

Example:   
```
A DB 0,1,2,3,4,5,6,7,8,9
B DB 10 DUP(0)
cld 
lea si,A
lea di,B
mov cx,10
rep movsb
```
2. Modify the Program for Multi-Digit Data Transfer and Display
  - Modify the program so that it transfers and displays 1-, 2-, and 3-digit data. To convert binary code to ASCII, use the division by 10 instruction.
### Lab Work #3 Subroutines and Parameter Passing  
[Solution](lab_3_v5/)
### Task Overview:
1. Write a Program Fragment in Assembly Language - Addition of Two Double Words
  - Write a program fragment in assembly language to add two double words (64-bit integers). Implement it as a subroutine with parameters using inline assembly in the C environment. The operands should be stored in memory (allocate space for them using C language features).
3. Implement Subroutine Calls with Parameter Passing via Stack:
  - Intrasegmental (Tiny memory model):
      - Implement a subroutine call where parameters are passed via the stack within the same segment (intrasegmental) using the Tiny memory model.
  - Intersegmental (Large memory model):
      - Implement a subroutine call where parameters are passed via the stack across different segments (intersegmental) using the Large memory model.
  - Provide a table showing the stack layout in both cases and highlight the differences.
3. Implement Parameter Passing to a Subroutine and Returning Results from a Subroutine Using:
  - Registers:
      - Implement parameter passing and returning results using CPU registers.
  - Global Memory Area:
      - Implement parameter passing and returning results using a global memory area.

### Lab Work #4 FPU. Floating-point number encoding. Special numerical values. Special cases. 
[Solution](lab_4_v7/)
### Task Overview:
1. Write a program in Assembly (see example): Enter three numbers in a dialog, load them into the FPU registers, sum them, and output the result. Track the FPU's operation in the debugger. How are the FPU registers used? How does the limited precision of the mantissa affect the results?
2. Obtain a NaN (Not a Number) value in the FPU and display it in a register.
3. Read and analyze the FPU registers: the status register and the control register.
4. Write a program that executes FPU commands, triggers, and responds to a special FPU case (an interrupt handler reports the occurrence of a special case by analyzing the status register).
5. When submitting your work, demonstrate to the instructor the process of converting a number, such as 16.02, to floating-point format.
Example:
```
asm { finit
fld ad
fld bb
fadd
fstp bb
}
cout<<" Acc "<<bb;
```
## Coursework Project
### Task Overview:
Create a program for declension of the male surname into the genitive case. Use a dialog like this to organize:
Example:   
```
- Vishnevskiy
- Net Vishnevskogo
```
[Solution](course-work/)
