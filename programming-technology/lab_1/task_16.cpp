//В массиве целых чисел определить, есть ли повторяющиеся элементы между заданными
//индексами M и N (включительно)
// Напишите
//функцию main, в которой примените вашу функцию для нескольких массивов:
// Для встроенных массивов, количество и значения элементов которых заданы при
//инициализации. Создайте несколько массивов, чтобы протестировать различные случаи.
// Для массива, размещённого в динамической памяти, количество элементов которого
//должно быть введено с клавиатуры, а значения элементов сгенерированы случайно.
#include <iostream>


bool isDuplicateElement(const int *array, int N, int M) {
    bool res = false;
    for (int i = N; i <= M; i++) {
        for (int j = i + 1; j <= M; j++) {
            if (array[i] == array[j]) {
                res = true;
                return res;
            }
        }
    }
    return res;
}


int main() {
    // Создание встроенных массивов разными способами:
    const int SIZE_1 = 10;
    int array1[SIZE_1] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

    const int SIZE_2 = 8;
    int array2[SIZE_2]{2, 2, 2, 3, 4};

    int array3[] = {0, 1, 0, 0, 2, 4, 3};

    int array4[5] = {0};


    std::cout << "Result 1: " << isDuplicateElement(array1, 0, 9) << '\n'; // 0
    std::cout << "Result 2: " << isDuplicateElement(array2, 4, 8) << '\n'; // 1
    std::cout << "Result 3: " << isDuplicateElement(array3, 3, 6) << '\n'; // 0
    std::cout << "Result 4: " << isDuplicateElement(array4, 0, 5) << '\n'; // 1

//Создание динамического массива количество элементов которого
//введено с клавиатуры, а значения элементов сгенерированы случайно.
    int size;
    std::cout << "Enter size of the dynamic array:";
    std::cin >> size;
    int *array5 = new int[size];
    for (int i = 0; i < size; i++) {
        array5[i] = rand() % 41 - 10;
        std::cout << array5[i] << '\n';
    }

    int n5;
    std::cout << "Enter the beginning of the interval:";
    std::cin >> n5;

    int m5;
    std::cout << "Enter the end of the interval:";
    std::cin >> m5;

    std::cout << "Result 5: " << isDuplicateElement(array5, n5, m5) << '\n';

    delete[] array5;

    return 0;
}


