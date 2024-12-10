# Object-Oriented Programming (OOP)
This folder contains lab works for the course "Object-Oriented Programming".

## Lab Works
## Lab 1: Vector task
### Task Overview:
- Write an algorithm to sort the contents of a vector of integers using the operator `operator[]`.
- Write an algorithm to sort the contents of a vector of integers using the `at()` method.
- Write an algorithm to sort the contents of a vector of integers using only iterators to access the elements of the vector. You are allowed to use only operators to get the current element and move to the next one (hint: you can save a copy of an iterator pointing to a specific element).
- Read the contents of a text file into a built-in C array and copy the data into a vector in a single line of code (without using loops or STL algorithms).
- Write a program that stores numbers entered from standard input into a vector (the input ends when the number 0 is entered). Remove all elements divisible by 2 (without using STL algorithms) if the last number is 1. If the last number is 2, add three ones (1) after every number divisible by 3.
- Write a function `void fillRandom(double* array, int size)` that fills an array with random values in the range from -1.0 to 1.0. Use this function to fill vectors of sizes 5, 10, 25, 50, and 100, and sort their contents using any sorting algorithm you developed earlier, modified to handle floating-point numbers.

  [Solution](lab_1/)

## Lab 2: String
### Task Overview:
Write a program that should perform the following tasks:
1. Read the content of a text file. The file may contain:
     - Words: Composed of Latin uppercase and lowercase letters as well as digits. The length of a word must not exceed 20 characters.
    - Punctuation marks: ., ,, !, ?, :, ;.
    - Whitespace characters: Space, tabulation, and newline characters.
2. Format the text as follows:
     - All whitespace characters other than spaces must be removed.
     - Consecutive spaces must be reduced to a single space.
     - There should be no space between a word and a punctuation mark.
     - There must always be a space after a punctuation mark.
     - Words longer than 10 characters must be replaced with the word "Vau!!!".
3. Transform the formatted text into lines such that:
     - Each line contains whole words (a word must not be split between lines).
     - The length of each line must not exceed 40 characters.

**Hints:** 
- You can store the entire input text in a single string.
- Create strings containing characters belonging to specific categories, such as punctuation marks.
- Use a vector<string> to store the resulting lines.
  [Solution](lab_2/)

## Lab 3: List Deque
### Task Overview:
1. Implement a priority queue class with the following behavior:
    - Each element has a priority: LOW, NORMAL, or HIGH.
    - Elements are dequeued based on priority: HIGH first, then NORMAL, and LOW. Elements with the same priority are dequeued in the order they were added.
    - Support an "accelerate" operation: all LOW priority elements are promoted to HIGH and processed before NORMAL priority elements.
    - Use `std::list` or `std::deque` for implementation, and explain your choice.
      
  Class interface:
          typedef enum { LOW, NORMAL, HIGH } ElementPriority;
          
          typedef struct {
              std::string name;
          } QueueElement;
          
          class QueueWithPriority {
          public:
              QueueWithPriority();
              ~QueueWithPriority();
              void PutElementToQueue(const QueueElement& element, ElementPriority priority);
              QueueElement GetElementFromQueue();
              void Accelerate();
          };
       
2. Write a program that:
     - Fills a list<int> with 15 random integers from 1 to 20. The list may contain from 0 to 20 elements. Test with sizes: 0, 1, 2, 3, 4, 5, 7, 14.
     - Outputs the list in the order: first element, last element, second element, second-to-last element, third element, and so on.
Example:

            Input list:
            1 2 3 4 5 6 7 8
            Output:
            1 8 2 7 3 6 4 5

Use recursion and bidirectional iterators to achieve the output.
  [Solution](lab_3/)

## Lab 4: Iterators task
### Task Overview:
Write a program for a "Phone Book".
Entries (name and phone number) should be stored in an STL container (vector or list). Ideally, the container type should affect only one line in the program — the declaration of the container (hint: use typedef).

The program should support the following operations:
- View the current record.
- Move to the next record.
- Move to the previous record.
- Insert a record before/after the currently viewed record.
- Replace the current record.
- Insert a record at the end of the database.
- Move forward/backward by n records.

Note: After inserting an element, iterators become invalid, so it's advisable to reset the iterator to the beginning of the database after an insertion.

Try to implement insertion and replacement operations using the same function. Depending on the required action, pass either a normal iterator or an insertion adapter (e.g., void modifyRecord(iterator pCurrentRecord, CRecord newRecord)).

The program can automatically populate the phone book with some initial entries upon startup without requiring user input.

  [Solution](lab_4/)

## Lab 5: Algorithm sort task
### Task Overview:
Write a program that performs the following actions:
1. Fills a `vector<DataStruct>` with `DataStruct` structures, where:
     - `key1` and `key2` are randomly generated in the range from -5 to 5.
     - `str` is filled with random strings from a predefined table (the table contains 10 arbitrary strings, and the index of the string is chosen randomly).

2. Prints the generated vector.
3. Sorts the vector as follows:
     - By increasing order of `key1`.
     - If `key1` values are the same, by increasing order of `key2`.
     - If both `key1` and `key2` are the same, by increasing order of the length of `str`.
Prints the sorted vector.

`DataStruct` is defined as follows:

    typedef struct {
        int key1;
        int key2;
        string str;
    } DataStruct;

  [Solution](lab_5/)

## Lab 6: Algorithm task
### Task Overview:
### Task 1: Text Processing
Write a program that:
- Reads the contents of a text file.
- Extracts words. A word is defined as a sequence of characters separated by spaces, tabs, or newline characters.
- Outputs a list of unique words (each word appears only once in the list).

### Task 2: Geometric Shapes
Write a program that:
- Fills a vector with geometric shapes (Shape). A shape can be a triangle, square, rectangle, or pentagon (structure provided below).
- Counts the total number of vertices of all shapes in the vector.
- Counts the number of triangles, squares, and rectangles.
- Removes all pentagons from the vector.
- Creates a vector<Point> containing one vertex (any) from each shape in the vector.
- Rearranges the vector to place all triangles first, followed by squares and rectangles.
- Prints the vector after each step.
  Structure Definitions:

      typedef struct {
          int vertex_num;            // Number of vertices: triangle = 3, square/rectangle = 4, pentagon = 5
          vector<Point> vertexes;    // Vector of vertex coordinates
      } Shape;
      
      typedef struct {
          int x, y;                  // Coordinates of a point
      } Point;

  
  [Solution](lab_6/)

## Lab 7: Functors task
### Task Overview:
Develop a functor to collect statistics from a sequence of integers (the sequence may contain numbers in the range from -500 to 500). After processing the sequence with the for_each algorithm, the functor should provide the following statistics:
- The maximum number in the sequence.
- The minimum number in the sequence.
- The average value of the sequence.
- The count of positive numbers.
- The count of negative numbers.
- The sum of odd elements in the sequence.
- The sum of even elements in the sequence.
- Whether the first and last elements of the sequence are the same.

Test the program with randomly generated sequences.

  [Solution](lab_7/)

  ## Lab 8: Functors2 task
  ### Task Overview:
### Task 1: Multiply List Elements by PI
Develop a program that multiplies each element of a list of floating-point numbers by PI, using only standard algorithms and functors.

### Task 2: Hierarchy of Geometric Shapes
Develop a program that:
1. Implements a hierarchy of geometric shapes:

Class Shape:
  - Contains information about the position of the shape's center (coordinates x and y).
  - Includes a method IsMoreLeft to determine if the shape is positioned to the left (based on the center position) of another shape passed as an argument.
  - Includes a method IsUpper to determine if the shape is positioned higher (based on the center position) than another shape passed as an argument.
  - Defines a pure virtual method Draw, which each derived shape implements to display its name and center position.

Class Circle: Derived from Shape, implements Draw.

Class Triangle: Derived from Shape, implements Draw.

Class Square: Derived from Shape, implements Draw.

2. Uses a list<Shape*> to store pointers to various shapes.
3. Displays (Draw) all shapes using standard algorithms and adapters.
5. Sorts the list from left to right (shapes with smaller x coordinates first) using standard algorithms and adapters, then displays (Draw) the sorted shapes.
6. Sorts the list from right to left (shapes with larger x coordinates first) using standard algorithms and adapters, then displays (Draw) the sorted shapes.
7. Sorts the list from top to bottom (shapes with smaller y coordinates first) using standard algorithms and adapters, then displays (Draw) the sorted shapes.
8. Sorts the list from bottom to top (shapes with larger y coordinates first) using standard algorithms and adapters, then displays (Draw) the sorted shapes.

[Solution](lab_8/)

Each lab work includes detailed descriptions, code solutions, and necessary explanations.

