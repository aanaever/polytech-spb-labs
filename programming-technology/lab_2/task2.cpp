#include <iostream>
#include <iomanip>
#include <array>
#include<fstream>

int main() {
    while (true) {
        int N;
        std::cout << "Enter size of the dynamic array:";
        std::cin >> N;

        if (N == 0) {
            break;
        } else {
            int array[N][N];
            int iBeg = N;
            int iEnd = 0;
            int jBeg = 0;
            int jEnd = N;
            int value = 0;

            while (value < N * N) {
                for (int i = --iBeg; i >= iEnd; i--)
                    array[i][jBeg] = ++value;
                for (int i = ++jBeg; i < jEnd; i++)
                    array[iEnd][i] = ++value;
                for (int i = ++iEnd; i < iBeg; i++)
                    array[i][jEnd - 1] = ++value;
                for (int i = --jEnd; i >= jBeg; i--)
                    array[iBeg][i] = ++value;
            }

            for (int i = 0; i < N; i++) {
                for (int j = 0; j < N; j++)
                    std::cout << std::setw(3) << array[i][j];
                std::cout << std::endl;
            }
        }
    }
    return 0;

}

