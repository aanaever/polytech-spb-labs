#include <iostream>
#include <stdio.h>
#include <stdlib.h> 

int main(void) {
    int aa;

    system("cls"); 

    // 1. Example of using the JL (Jump Less) instruction
    __asm {
        mov ax, 2       // Place the value 2 into ax
        mov bx, 4       // Place the value 4 into bx
        cmp ax, bx      // Compare ax and bx
        jl metka        // Jump to the label if ax < bx (2 < 4)
        mov ax, 8       // If ax >= bx, place the value 8 into ax
    }

metka:
    __asm {
        mov ax, 10      // When jumping to the label, place the value 10 into ax
    }

    // 2. Example of using the ROL instruction
    __asm {
        mov ax, 1       // Place the value 1 into ax
        mov cl, 1       // Place the value 1 into cl (counter register)
        rol ax, cl      // Rotate ax left by cl (1) bit
    }

    // 3. Example of using the LEA instruction
    __asm {
        lea ax, aa      // Place the address of variable aa into ax
    }

    // 4. Example of using the NOP instruction
    __asm {
        nop             // The instruction does nothing, used for a small delay
    }

    // 5. Example of using the AND instruction
    __asm {
        mov ax, 2       // Place the value 2 into ax
        mov bx, 4       // Place the value 4 into bx
        and ax, bx      // Perform a bitwise AND between ax and bx, the result is 0
    }

    // Task 2: Array transfer using LOOP and LEA instructions
    int A1[10] = { 2,1,2,3,4,5,6,7,8,9 };
    int B1[10] = { 0,0,0,0,0,0,0,0,0,0 };

    __asm {
        cld                     // Set the direction flag forward
        lea esi, A1             // Load the address of array A1 into ESI
        lea edi, B1             // Load the address of array B1 into EDI
        mov ecx, 10             // Set the counter to 10 iterations
        rep movsd               // Copy ECX double words (4 bytes) from A1 to B1
    }

    // Output the intermediate result for debugging
    printf("After moving A1 to B1:\n");
    for (int i = 0; i < 10; i++) {
        printf("B1[%d] = %d\n", i, B1[i]);
    }

    // Task 3: Data transfer using MOVS and REP prefix
    int A2[10] = { 2,1,2,3,4,5,6,7,8,9 };
    int B2[10] = { 0,0,0,0,0,0,0,0,0,0 };

    __asm {
        cld                     // Set the direction flag forward
        lea esi, A2             // Load the address of array A2 into ESI
        lea edi, B2             // Load the address of array B2 into EDI
        mov ecx, 10             // Set the counter to 10 words
        rep movsd               // Copy ECX double words (4 bytes) from A2 to B2
    }

    // Output the intermediate result for debugging
    printf("After moving A2 to B2:\n");
    for (int i = 0; i < 10; i++) {
        printf("B2[%d] = %d\n", i, B2[i]);
    }

    // Task 4: Data transfer in LARGE memory model using LES (LDS) instructions
    int A3[10] = { 2,1,2,3,4,5,6,7,8,9 };
    int B3[10] = { 0,0,0,0,0,0,0,0,0,0 };

    __asm {
        cld                     // Set the direction flag forward
        les edi, B3             // Load the address of array B3 into ES:EDI
        lds esi, A3             // Load the address of array A3 into DS:ESI
        mov ecx, 10             // Set the counter to 10 words
        rep movsd               // Copy ECX double words (4 bytes) from A3 to B3
    }

    // Output the intermediate result for debugging
    printf("After moving A3 to B3:\n");
    for (int i = 0; i < 10; i++) {
        printf("B3[%d] = %d\n", i, B3[i]);
    }

    return 0;
}
