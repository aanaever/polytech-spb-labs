# Computational Math

This folder contains lab works for the course "Computational Math".

## Lab Works
### **Lab 1:** Investigation of the relationship of the condition number using the DECOMP and SOLVE programs. [Solution](lab_1/)
#### Task Overview:
Create a procedure for calculating matrix R based on the given matrix $A(N, N)$:

```math
R = A^{-1} \cdot A - E
```
  and its norm:

```math
||R|| = \max_k \sum_{j}^{N} |R_{j,k}|
```

Construct three matrices $A$ where:

```math
x_k = \frac{1 + \cos(k)}{\sin^2(k)}, \quad k = 1, \dots, 4
```
and
```math
x_5 = \frac{1 + \cos(1)}{\sin^2(1 + \varepsilon)}
```

for three values of $ε$= 0.001, 0.00001, 0.000001, and $N$ = 5.

Matrix $A$ is structured as follows:

```math
A = 
\begin{pmatrix}
1 & 1 & 1 & 1 \\
x_1 & x_2 & \dots & x_N \\
\dots & \dots & \dots & \dots \\
x_1^{N-1} & x_2^{N-1} & \dots & x_N^{N-1} \\
\end{pmatrix}
```

Investigate the dependence of the error in calculating $||R||$ on $ε$. 

### **Lab 2:** Construction of a spline function and finding the root of the equation using the SPLINE and SEVAL programs. [Solution](lab_2/)
#### Task Overview:
For the given tabulated function f(x):

|   x  | 1.0  | 1.2  | 1.5  | 1.6  | 1.8  | 2.0  |
|-------|-------|-------|------|------|------|------|
| f(x) | 5.000 | 6.899 | 11.180 | 13.133 | 18.119 | 25.000 |

Construct a spline function and use it to find the root of the equation:

```math
f(x) = 6x + 3
```

on the interval [1, 2] using the bisection method.

### **Lab 3:** Solving the system of differential equations using the RKF45 program and the second-order Runge-Kutta method. [Solution](lab_3/)
#### Task Overview:

Solve the following system of differential equations:

```math
\frac{dx_1}{dt} = -155x_1 - 750x_2 + \sin(1 + t); \quad \frac{dx_2}{dt} = x_1 + \cos(1 - t) + t + 1;
```
```math
x_1(0) = 5, \quad x_2(0) = -1; \quad t \in [0, 1]; \quad h_{print} = 0.04;
```

using the following methods with the same printing step:

1. Using the **RKF45** program with EPS = 0.0001;
2. Using the **Runge-Kutta method** of second-order accuracy:

```math
z_{n+1} = z_n + (k_1 + 3k_2) / 4;
```
```math
k_1 = hf(t_n, z_n);
```
```math
k_2 = hf(t_n + 2h/3, z_n + 2k_1 / 3)
```
with two constant integration step sizes:
   - a) $h_{int} = 0.02;$
   - b) any other step size that provides a qualitatively correct solution.

Compare the results.

### **Lab 4:** Choosing the method of interpolation for the population data table of the USA. [Solution](lab_4/)
#### Task Overview:
Choice of Interpolation Method for the Population Data Table of the USA
The following data from the census bureau show the population of the USA:

| Year  | 1900     | 1910     | 1920     | 1930     | 1940     | 1950     | 1960     | 1970     |
|-------|----------|----------|----------|----------|----------|----------|----------|----------|
| Population | 75994575 | 91972266 | 105710620 | 122330000 | 131669275 | 150697361 | 179323175 | 203211926 |

Construct an interpolating polynomial for this data in two forms:

```math
\sum_{j=0}^{7} b_j (t - Q)^j \quad (1), \quad \sum_{j=0}^{7} d_j \left(\frac{t - P}{R}\right)^j \quad (2).
```

Find the coefficients $b_j$ and $d_j$ using the DECOMP and SOLVE subprograms.

The values of $Q$, $R$, and $P$ are given by the instructor. Which of the two methods is preferable?

Using this data, construct a spline function. Test all three constructed functions for the period from 1900 to 1980 with a 2-year interval. According to the census data, the population of the USA in 1980 was 222.2 million. What does interpolation give in this case? Evaluate the error of the results and the influence of the accuracy of the input data on the results.

### Variant №33C

```math
Q = 3105.659 \cdot \int_{\frac{\pi}{2}}^{\frac{\pi}{4}} \frac{\sin(x)}{x}  \, dx
```
```math
P = -5785.971 \cdot y^* , 
```

where $y^*$ is the negative root of the equation $1.8x^2 = \sin 10x$ on the interval $[-0.5, 0.1]$,
```math
R = 24.62175 \cdot z^* , 
```
where $z^*$ is the value of $z$ that minimizes the function $f(z)$ on the intervals $[1, 2]$

```math
f(z) = \left( z + \frac{1}{z} \right)^2 + (2 \ln z + z)(2 \ln z - z) - 4 \cdot \frac{\ln z}{z}
```


## Running the Lab Works

To run these lab works, you need a working Fortran environment with the necessary libraries. You may need to download and install a Fortran compiler such as [GFortran](https://gcc.gnu.org/fortran/) or [Intel Fortran Compiler](https://software.intel.com/content/www/us/en/develop/tools/oneapi/components/fortran-compiler.html).

### Installing GFortran

1. **Windows**: Download and install [MinGW-w64](http://mingw-w64.org/doku.php/download).
2. **macOS**: Install GFortran via Homebrew by running `brew install gcc`.
3. **Linux**: Install GFortran via your package manager. For example, on Debian-based systems, run `sudo apt-get install gfortran`.



Each lab work includes detailed descriptions, code solutions, and necessary explanations.
