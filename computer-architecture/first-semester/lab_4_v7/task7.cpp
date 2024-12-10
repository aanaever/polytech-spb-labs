#include <iostream>
#include <bitset>
using namespace std;

int main()
{
    setlocale(LC_ALL, "Russian");

    // Task #1: Sum three numbers using FPU

    float a, b, c;
    a = 2.34f;
    b = 4.77f;
    c = 2.0f;
    float sum = 0.0f;

    __asm
    {
        finit // Initialize FPU

        fld a // Load a into FPU stack
        fld b // Load b into FPU stack
        fld c // Load c into FPU stack

        fadd // Add c and b
        fadd // Add result to a

        fstp sum // Store the result in sum
    }
    cout << "Sum: " << sum << endl << endl;

    // Task #2: Obtain NaN (Not a Number) by dividing 0 by 0

    __asm
    {
        finit         // Initialize FPU
        fldz          // Load 0 onto the FPU stack
        fldz          // Load another 0 onto the FPU stack
        fdiv          // Divide 0 by 0, this will generate NaN
        fstp sum      // Store NaN in sum
    }
    cout << "Not a Number (NaN): " << sum << endl << endl;

    // Task #3: Analyze the FPU status and control words

    int sw, cw; 
    __asm
    {
        fstsw sw // Save the status word of FPU
        fstcw cw // Save the control word of FPU
    }
    cout << "FPU Status Word: " << bitset<16>(sw) << endl;
    cout << "FPU Control Word: " << bitset<16>(cw) << endl;

    // Task #4: Divide by 0 and check for FPU exception (special case)

    a = 2;
    b = 0;
    int fpuStatus;

    __asm
    {
        finit         // Initialize FPU
        fld a         // Load a into FPU stack
        fld b         // Load b into FPU stack
        fdiv          // Divide a by b (2 / 0)
        fstp sum      // Store the result in sum
        fstsw fpuStatus // Save the FPU status word
    }
    cout << "Division by 0 result: " << sum << endl << endl;

    // Check if division by zero triggered a special case (exception)
    if (fpuStatus & 0x0400) {
        cout << "Special case: Division by 0 detected!" << endl;
    } else {
        cout << "No division by 0 error occurred." << endl;
    }

    // Task #5: Conversion of 16.02 to floating point format
    /*
    Initially, we have the number 16.02

    Convert 16 to binary = 10000

    Convert .02 to binary: multiply the fractional part by 2 and note the integer part
    0.02 * 2 = 0.04
    0.04 * 2 = 0.08
    0.08 * 2 = 0.16
    0.16 * 2 = 0.32
    0.32 * 2 = 0.64
    0.64 * 2 = 1.28
    0.28 * 2 = 0.56
    0.56 * 2 = 1.12
    0.12 * 2 = 0.24
    0.24 * 2 = 0.48
    0.48 * 2 = 0.96
    0.96 * 2 = 1.92
    0.92 * 2 = 1.84
    0.84 * 2 = 1.68
    0.68 * 2 = 1.36
    0.36 * 2 = 0.72
    0.72 * 2 = 1.44
    0.44 * 2 = 0.88
    0.88 * 2 = 1.76

    So, we write the number in binary: 10000.0000010100011110101
    Normalize it to get: 1.00000000010100011110101 * 2^4

    The true exponent is 4.
    Mantissa is everything after the binary point.
    Sign is positive, so it's 0.
    Exponent is the bias + true exponent, that is:
    01111111 + 100 = 10000011

    So, the final binary representation is:

    0 10000011 00000000010100011110101
    Or
    0100 0001 1000 0000 0010 1000 1111 0101
    Or
    418028F5
    */

    return 0;
}
