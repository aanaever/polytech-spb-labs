#include <iostream>
#include <cmath>

bool isSimpleNumber(int number){
    if(number < 2){
        return false;
    }
    for (int i = 2; i <= std::sqrt(number); ++i){
        if(number % i == 0) {
            return false;
        }
    }
    return true;
}

int main() {
    int number = 0;
    std::cout << "Enter a number: " << "\n";
    std::cin >> number;

    if (isSimpleNumber(number)){
        std::cout << "Number is Simple  " << std::endl;
    } else {
        std::cout << "Number isn't Simple" << std::endl;
    }
    return 0;
}
