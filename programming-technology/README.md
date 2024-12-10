# Programming Technology 

This folder contains lab works for the course "Programming Technology".

## Lab Works

### **Lab 1:** 
Write a function that checks if there are any duplicate elements in an array of integers within a specified range of indices from M to N (inclusive). Test this function in the main method for several cases:

- For arrays created at initialization with a fixed number of elements and values. Create several arrays to test different cases.
- For an array created dynamically: the number of elements should be entered from the keyboard, and the values of the elements should be randomly generated.  [Solution](lab_1/)

### **Lab 2:** 
Write a function that fills an N * N matrix with natural numbers from 1 to  N * N in a spiral pattern, starting from the lower-left corner and spiraling clockwise. The matrix should be dynamically allocated in memory. The dimension of the matrix should be entered from the keyboard, and the result should be printed on the screen and written to a file. The operation should be repeated until the input size is zero.  [Solution](lab_2/)

### **Lab 3:** 
Write two functions that create a new string from two input strings, adding to the first string all the characters from the second string that are decimal digits.
- Function for C-style strings:
The function should accept pointers to C-style strings and return the resulting string. The result string is passed to the function as a parameter and is not dynamically allocated within the function. The string should end with the '\0' character
- Function for $std::string$ type strings:
T- he function should accept strings of type std::string and return the resulting string. The result is returned by value.

Main program:
- Reads strings from a file: the file may contain multiple strings. Each string is described by two lines: the first line is the number of characters, and the second line contains the characters of the string.
  - For C-style strings, memory is dynamically allocated.
  - For $std::string$, the copy constructor is used to work with the string.
The program outputs the results of both functions to the screen. [Solution](lab_3/)

### **Lab 4:** 
Develop a Class for Working with 2D Vectors.

The class must support the following operations:
- Addition of vectors.
- Dot product of two vectors.
- Calculation of the vector length.
- Multiplication of a vector by a scalar.

Implementation Requirements:

- More than one class may be created if it makes sense for the solution.
- Necessary constructors must be implemented.
- Accessor methods for class fields should be provided if needed.
- The << operator must be overloaded to output vector information to a stream.
- Classes must validate their data and prevent objects from being created in an invalid state (exceptions can be thrown using throw).
- Some methods may be implemented as overloaded operators, where appropriate.
- The class must be declared in a header file (.h) with a proper header guard.
- Class methods must be implemented in a separate implementation file (.cpp).
  
The functionality of all implemented methods and constructors must be demonstrated in the main function. [Solution](lab_4/)
## Tasks

### **Task 1:** 
The coordinates of a bishop (elephant) on a chessboard are given (row and column number). Write a loop (or loops) to output the coordinates of all cells that are under attack. The bishop can move any number of squares diagonally. [Solution](tasks/task_1.cpp)

### **Task 2:**
Write a program that performs the following operations for a sequence of integers ending with zero (zero is not considered part of the sequence):

- Calculate the sum of all entered numbers.
- Calculate the arithmetic mean of all entered numbers.
- Calculate the arithmetic mean of positive numbers.
- Find the maximum value and its position in the sequence.
- Find the smallest positive value and its position in the sequence.

Constraints:
- Arrays are not allowed.
- Use only a precondition loop (while loop). [Solution](tasks/task_2.cpp)

### **Task 3:**
Write a function that determines whether a number is prime.
A prime number is defined as a number that is divisible only by 1 and itself (e.g., 2, 3, 5, 7, 11, 13, …).
Write a program that outputs all positive prime numbers less than a given number. [Solution](tasks/task_3.cpp)


### **Task 4:**
Write a function to calculate the value of a definite integral.
- The integrand can be hardcoded in the program.
- Use numerical integration with the rectangle method or trapezoidal rule.
- Determine accuracy using the Runge rule. [Solution](tasks/task_4.cpp)

### **Task 5:**

Write a function to calculate the value of the given sum at a specified point ($x$) with a defined absolute error (absError) and a maximum number of terms (nMax):

```math

\frac{1}{\sqrt{1 + x}} = 1 - \frac{1}{2}x + \frac{1 \cdot 3}{2 \cdot 4}x^2 - \frac{1 \cdot 3 \cdot 5}{2 \cdot 4 \cdot 6}x^3 + \dots,
\quad \text{for } x \in (-1, 1),

```
Requirements:
- Absolute Error (absError) represents the absolute value of the first discarded term of the series.
- If the number of terms exceeds nMax, if the accuracy is not achieved, or if x is outside the interval (−1,1) (−1,1), the function should throw an exception:

      throw "Error!";
Example of exception handling:

    try {
    // Your code that calls the function
    } catch (const char *e) {
    std::cerr << e << '\n';
    }

- Each successive term must be derived from the previous term. Direct exponentiation functions are not allowed.

Write a program to output a table of calculated function values over a specified interval (interval, step, and accuracy should be entered via cin) and the values obtained using standard C++ functions. Include the <cmath> header for standard functions. [Solution](tasks/task_5.cpp)


### Installing
To set up the environment for running the lab works:

- Install a C++ compiler:
  -   For Linux/macOS: Install GCC/G++ via your package manager (e.g., `sudo apt install g++` for Ubuntu).
    - For Windows: Install MinGW or use an IDE like Visual Studio that includes a compiler.
- Install a text editor or IDE for editing code:
    Popular choices include Visual Studio Code, CLion.
- Optional: Install CMake for managing larger projects or building more complex code bases.


Each lab work includes detailed descriptions, code solutions, and necessary explanations.
