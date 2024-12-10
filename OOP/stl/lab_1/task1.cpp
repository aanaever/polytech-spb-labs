//
// Created by Hokage on 19.02.2023.
//1) алгоритм сортировки вектора целых чисел, используя оператор operator[].
//2) алгоритм сортировки вектора целых чисел, используя метод at().
//3) алгоритм сортировки вектора целых чисел, используя для доступа к содержимому вектора только итераторы.
// Для работы с итераторами допустимо использовать только операторы получения текущего элемента и перехода
// в следующему (подсказка, можно сохранять копию итератора указывающего на некоторый элемент).
//4) Прочитайте во встроенный массив С содержимое текстового файлы,
// скопируйте данные в вектор одной строкой кода (без циклов и алгоритмов STL)
// 5)	Напишите программу, сохраняющую в векторе числа, полученные из стандартного ввода
// (окончанием ввода является число 0).
// Удалите все элементы, которые делятся на 2 (не используете стандартные алгоритмы STL), если последнее число 1.
// Если последнее число 2, добавьте после каждого числа которое делится на 3 три единицы.
// 6)	Напишите функцию void fillRandom(double* array, int size) заполняющую массив случайными значениями в интервале от -1.0 до 1.0.
// Заполните с помощью заданной функции вектора размером 5,10,25,50,100 и отсортируйте его содержимое (с помощью любого разработанного ранее алгоритма модифицированного для сортировки действительных чисел)

#include <iostream>
#include <vector>
#include <chrono>
using namespace std;

// 1) bubble sorting using operator []
void sortByOperator(vector <int>& vector) {
   int n = vector.size();
    for (int i = 0; i < n; i++) {
        for (int j = j + 1; j < n; j++) {
            if (vector[i] > vector[j]) {
                int temp = vector[i];
                vector[i] = vector[j];
                vector[j] = temp;
            }
        }
    }
}

// 2) bubble sorting using method at()
vector <int> sortByAt(vector <int> vector2){
    for (int i = 0; i < vector2.size(); ++i) {
        for (int j = 0; j < vector2.size(); ++j) {
            if (vector2.at(i) < vector2.at(j)){
                swap(vector2.at(i), vector2.at(j));
            }
        }
    }
    return vector2;
}
// 3) bubble sorting using iterator
vector <int> sortByIterator(vector <int> vector3){
    int temp;
    vector <int>::iterator iterator;
    for (iterator = vector3.begin();  iterator < --vector3.end(); iterator++) {
        if (*iterator > *(iterator + 1)){
            temp = *iterator;
            *iterator = *(iterator + 1);
            *(iterator + 1) = temp;
        }
    }
    return vector3;
}

int main() {

 //1
 vector<int> vector1 = {6, 8, 9, 9, 2, 1, 3};
 auto start_time = chrono::steady_clock::now(); // начало измерения времени
 sortByOperator(vector1);
 auto end_time = chrono::steady_clock::now(); // конец измерения времени

}

