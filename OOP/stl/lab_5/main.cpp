
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <ctime>
#include <string>

using namespace std;

typedef struct
{
    int key1;
    int key2;
    string str;
} DataStruct;

const vector<std::string> table = {"first", "second", "third", "fourth", "five",
                                   "six", "seven", "eight", "nine", "ten"};


void print_vector(const std::vector<DataStruct> &v)
{
    for (const auto &e : v)
    {
        std::cout << "key1: " << e.key1 << " key2: " << e.key2 << " str: " << e.str << std::endl;
    }
}

int main() {
    srand(static_cast<unsigned>(std::time(nullptr)));

    vector<DataStruct> data;

    for (int i = 0; i < 10; ++i)
    {
        DataStruct elem;
        elem.key1 = (rand() % 11) - 5; 
        elem.key2 = (rand() % 11) - 5;
        elem.str = table[rand() % 10];  
        data.push_back(elem); 
    }

    std::cout << "Vector:" << std::endl;
    print_vector(data);

  
    std::sort(data.begin(), data.end(), [](const DataStruct &a, const DataStruct &b) {
        if (a.key1 != b.key1)
            return a.key1 < b.key1;
        if (a.key2 != b.key2)
            return a.key2 < b.key2;
        return a.str.length() < b.str.length();
    });

    std::cout << "\nSorted vector:" << std::endl;
    print_vector(data);

    return 0;
}
