# Algorithms and Data Structures

This folder contains lab works for the course "Algorithms and Data Structures".

## Lab Works
## Laboratory Work 1-4: Group Member Sorting
### Task Overview:
Given a list of group members in the following format:

   *ФАМИЛИЯ       И. О.     ПОЛ     ГОД РОЖДЕНИЯ*

   *15 chars      5 chars   1 char  4 chars*
 
   The task is to form sorted lists of men and women in descending order of age. The sorting should be done using different methods and data structures in each laboratory work.
### Example Output File:
   *Мужчины:*  
   *Иванов И. Л. М 1985*  
   *Женщины:*  
   *Петрова Д. О. Ж 1983*   
### Lab 1-4 Summary:
Each laboratory task implements the same goal but uses different programming techniques and data structures to achieve it.
### Lab 1:
   - Approach: Arrays of strings and regular programming.
   - Description: In this lab, group member data is stored and manipulated using arrays of strings. The sorting is done using the selection sort algorithm, and regular - programming techniques are used to handle the data.
   - Solution: [Lab_1](lab_1/).
### Lab 2:
   - Approach: Character arrays and internal procedures of the main program with regular programming.
   - Description: This lab focuses on using character arrays instead of string arrays. Internal procedures within the main program are utilized to manage and process the data. Regular programming is again employed for text manipulation.
   - Solution: [Lab_2](lab_2/).
### Lab 3:
   - Approach: Arrays of structures, record files, modules, and regular programming.
   - Description: The data is managed using arrays of structures, allowing for a more organized and modular approach. The lab introduces the use of record files for storing data and modules for organizing the code. Regular programming techniques are also applied.
   - Solution: [Lab_3](lab_3/).
### Lab 4:
   - Approach: Singly linked lists of unknown length, modules, tail recursion, and regular programming.
   - Description: In this lab, dynamic data structures are introduced with the use of singly linked lists, which allow for handling data of unknown length. Tail recursion is used for processing the lists, and regular programming continues to be a key component in text processing. The solution is modular, ensuring code reusability and clarity.
   - Solution: [Lab_4](lab_4/).

## Laboratory Work 5-6: File Name Searching
### Task Overview:
The task is to develop a pure subroutine for searching file names in a list based on a given pattern. For example, if the input string is `wi*.*`, the subroutine should return the file names with any extension but starting with the letters `wi`.

### Example Input:
      wi*.*

### Example Output:
      File 1: wi_start.txt
      File 2: wi_data.csv


### Lab 5-6 Summary:
Each laboratory task implements the same goal but uses different programming techniques and data structures to achieve it.
### Lab 5:
   - Approach: Arrays of characters and internal procedures with regular programming.
   - Description: In this lab, the file names are stored and processed using arrays of characters. The list of file names is filtered and matched against the given pattern using internal procedures. Regular programming is applied to handle the string operations efficiently.
   - Solution: [Lab_5](lab_5/).
### Lab 6:
   - Approach: Singly linked lists of unknown length, modules, tail recursion, and regular programming.
   - Description: This lab enhances the approach by using dynamic singly linked lists of unknown length. The file names are processed as elements in these lists, and the list is sorted and filtered based on the given pattern. Tail recursion is employed for processing the lists, and regular programming techniques are used for pattern matching. The solution is organized into two modules, ensuring clear separation of concerns and reusability of code.
   - Solution: [Lab_6](lab_6/).


## Running the Lab Works

To run these lab works, you need a working Fortran environment with the necessary libraries. You may need to download and install a Fortran compiler such as [GFortran](https://gcc.gnu.org/fortran/) or [Intel Fortran Compiler](https://software.intel.com/content/www/us/en/develop/tools/oneapi/components/fortran-compiler.html).

### Installing GFortran

1. **Windows**: Download and install [MinGW-w64](http://mingw-w64.org/doku.php/download).
2. **macOS**: Install GFortran via Homebrew by running `brew install gcc`.
3. **Linux**: Install GFortran via your package manager. For example, on Debian-based systems, run `sudo apt-get install gfortran`.


Each lab work includes detailed descriptions, code solutions, and necessary explanations.
