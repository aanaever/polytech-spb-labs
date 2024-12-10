#include <iostream>
#include <fstream>


void fillAndPrintMatrix(int N, int **array) {

    int iBeg = N;
    int iFin = 0;
    int jBeg = 0;
    int jFin = N;
    int value = 0;

    while (value < N * N) {
        for (int i = --iBeg; i >= iFin; i--) array[i][jBeg] = ++value;
        for (int i = ++jBeg; i < jFin; i++) array[iFin][i] = ++value;
        for (int i = ++iFin; i < iBeg; i++) array[i][jFin - 1] = ++value;
        for (int i = --jFin; i >= jBeg; i--) array[iBeg][i] = ++value;
    }

}

int main() {
    while (true) {
        int N;
        std::cout << "Enter size of the dynamic array:";
        std::cin >> N;

        if (N == 0) {
            break;
        } else {
            int **matrix = new int *[N];
            fillAndPrintMatrix(N, matrix);

            for (int i = 0; i < N; ++i) {
                for (int j = 0; j < N; ++j) {
                    std::cout << matrix[i][j];
                }
                std::cout << std::endl;
            }

            // std::ofstream out;
            // out.open("output.txt", std::ios::app);
            // if (out.is_open()) {
            //   for (int i = 0; i < N; ++i) {
            //  for (int j = 0; j < N; ++j) {
            //    out << matrix[i][j] << std::endl;
            //std::cout << matrix[i][j];
            //}
            //std::cout << std::endl;
            // }
            //}
            // out.close();

            for (int i = 0; i < N; ++i) {
                delete[] matrix[i];
            }
            delete[] matrix;
        }
    }
    return 0;

}


