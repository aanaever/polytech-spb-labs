#include <iostream>
#include <cmath> 

int main() {
    int x = 5;  
    int y = 1;  

    for (int i = 1; i <= 8; ++i) {
        for (int j = 1; j <= 8; ++j) {
            if (abs(i - x) == abs(j - y)) {
                std::cout << "Row: " << i << " Column: " << j << '\n'; 
            }
        }
    }

    return 0;
}
