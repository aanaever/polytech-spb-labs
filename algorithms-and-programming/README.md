# Algorithmization and Programming

This folder contains lab works for the course "Algorithmization and Programming".

## Lab Works

1. **Lab 1:** Given the values of the variables a, b, c. Perform a permutation of the values of these variables so that the variables a, b, c take the values of c, a, b, respectively. [Solution](lab_1/)

2. **Lab 2:** Given three values of an argument that satisfy the inequality $x_1 < x_2 < x_3$ and their corresponding function values $y_1, y_2, y_3$, for a given value $x \in [x_1, x_3]$, compute the function $y(x)$ using the piecewise linear interpolation formulas. [Solution](lab_2/)

  ```math
    y(x) = 
    \begin{cases} 
    y_1 + \frac{x - x_1}{x_2 - x_1} (y_2 - y_1), & \text{if } x_1 \leq x \leq x_2 ; \\
    y_2 + \frac{x - x_2}{x_3 - x_2} (y_3 - y_2), & \text{if } x_2 \leq x \leq x_3 .
    \end{cases}
  ```
3. **Lab 3:** Given the vector 𝐴(30), construct the vector 𝐵(10), where each element is equal to the sum of three consecutive elements of 𝐴, starting from the first (last). [Solution](lab_3/)

4. **Lab 4:** Compute the integral using the left rectangle method
        $I = \int_{0.1}^{0.4} e^x x^2 \, dx$ for $h = 0.002$. [Solution](lab_4/)

5. **Lab 5:** Given three arrays 𝐴(50 elements), 𝐵 (50 elements), and 𝐶 (50 elements), form arrays 𝐷 (50 elements) and 𝐹 (50 elements) according to the following rules:
 ```math
    d_i = \min(a_i, b_i, c_i)
 ```

```math
    f_i = \max(a_i, b_i, c_i)
```
   <p align="center">If $(a_i = b_i = c_i)$, then $(d_i = f_i)$. <a href="lab_5/">Solution</a></p>

6. **Lab 6:** Compute the value $( {y}=\frac{1}{a} \)$ using Newton's method, taking the initial approximation $( 0 < y_0 < \frac{2}{a} \)$ and using the equation $f(y) = \frac{y^2}{a} - a = 0 \$. [Solution](lab_6/)
 Newton's method to solve the nonlinear equation \( f(z) = 0 \):

 ```math
 z_{n+1} = z_n - \frac{f(z_n)}{f'(z_n)}
 ```

7. **Lab 7:** Sort the given sequence $a_1, a_2, \ldots, a_{100}$ so that $a_i \leq a_{i+1}$. [Solution](lab_7/)

8. **Lab 8:** In the row of the matrix 𝐵 (100, 20), which has the smallest sum (if there are several such sums, then the row with the smaller number), find the maximum and minimum elements and their indices. [Solution](lab_8/)

9. **Lab 9:** In the array 𝐴 (100, 50), find the element that is the largest. [Solution](lab_9/)
10. **Lab 10:** Sort the elements in the rows of the matrix 𝐵 (10, 15) so that  $|b_{ij}| \geq |b_{i(j+1)}|$. [Solution](lab_10/)
11. **Lab 11:** From the elements of the one-dimensional array 𝐴 (100), form a three-dimensional array 𝐶 (2, 10, 5) in such a way that the first index of the array 𝐶 changes the fastest. [Solution](lab_11/)
12. **Lab 12:** Develop an algorithm to compute the sum
$$S = \sum_{k=1}^{5} A^k Y$$
where $𝐴$ is a given square matrix of order 10, and  $Y$ is a given vector. Calculate the norm of $Y$ $(|| Y || = \max | y_i |)$ and print $S$ and $|| Y ||$. Provide a procedure for multiplying a matrix by a vector and a procedure function for calculating the norm of a vector. [Solution](lab_12/)

## Running the Lab Works

To run these lab works, you need a working Fortran environment with the necessary libraries. You may need to download and install a Fortran compiler such as [GFortran](https://gcc.gnu.org/fortran/) or [Intel Fortran Compiler](https://software.intel.com/content/www/us/en/develop/tools/oneapi/components/fortran-compiler.html).

### Installing GFortran

1. **Windows**: Download and install [MinGW-w64](http://mingw-w64.org/doku.php/download).
2. **macOS**: Install GFortran via Homebrew by running `brew install gcc`.
3. **Linux**: Install GFortran via your package manager. For example, on Debian-based systems, run `sudo apt-get install gfortran`.



Each lab work includes detailed descriptions, code solutions, and necessary explanations.
