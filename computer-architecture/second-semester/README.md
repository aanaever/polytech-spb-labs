# Computer Architecture

This folder contains lab works for the course "Computer Architecture".

## Lab Works
### Lab Work #1 BMP Сonverter
### Task Overview:
- Write a program to test the input file. Output its dimensions and the number of bits per pixel (8–24 bits). Use structures for testing.
- Write a BMP format converter program (24 to 16 bit). For image binarization (24 -> 1), a threshold level must be specified.
[Solution](lab_1/)

### Lab Work #2 SIMD Vector Programming Technologies
### Task Overview:
- Write a program "Exploring MMX-SSE-AVX Commands" similar to the example, but with new commands (it is necessary to use at least two "special" commands and one command for AVX registers). Explain and demonstrate in the Visual C++ debugger the execution of the commands and changes in the register contents.
"Special" commands can include:
    - Saturation operations,
    - Comparison,
    - Permutation,
    - Packing/unpacking,
    - SSE3, etc.
- Add three functions to the program with data formats __m64, __m128, __m256 from C libraries (#include <xmmintrin.h>, <mmintrin.h>, <immintrin.h>) that perform operations on the previously described arrays of type char and float. Show in the Disassembler the execution of commands on registers.

Example function:

      __m64 _mm_add_pi8(__m64 m1, __m64 m2)
- Write a program that processes arrays using their vector representation and the functions of the dvec library. Using the Disassembler, determine the number of machine commands used to execute the program.
[Solution](lab_2/)

### Lab Work #3 Programming for Multithreaded Applications Using OpenMP
### Task Overview:
- Load the test program. Do not forget to activate OpenMP directives in the project property pages by selecting Configuration Properties → C/C++ → Language and changing the OpenMP Support property.
- Experimentally confirm the parallel operation of two threads using the for and sections directives. Verify this by using the OMP_GET_NUM_THREADS directive. Explain and demonstrate the use of the barrier directive.
- Write a multithreaded program using two synchronization directives (single, critical, master, atomic, ordered, etc.). The synchronization directives should differ between students. The program can either display the thread number on the screen or populate an array using two threads with synchronization directives.
- Write a multithreaded program using synchronization based on locks:

      OMP_INIT_LOCK(var)
      OMP_SET_LOCK
      OMP_UNSET_LOCK
      OMP_TEST_LOCK.

  [Solution](lab_3/)

## Coursework
### Task Overview:
**Development of a Telegram Bot "Slide-Show"**

The Telegram bot allows users to create a video slideshow from images and an audio file. It is developed using various libraries, including:
- Ffmpeg for video processing.
- Telebot for interacting with the Telegram API.
- Subprocess for executing ffmpeg commands.
- Moviepy for handling the audio file and retrieving its duration.

  [Solution](myBot/)
