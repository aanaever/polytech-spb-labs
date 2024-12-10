#include <iostream>

int main(){
    int number =1;
    int i = 0;
    int j = 0;
    int sumAll = 0;
    int sumPositive = 0;
    double averPositive = 0.0;
    int max = 0;
    int maxNumber = 0;
    int minPositive = 0;
    int minPosNum = 0;
    double averageAll = 0;

    while(number != 0) {
        std::cin >> number;

        if (number != 0) {
            i++;
            sumAll = sumAll + number;
            if(number > max){
                maxNumber = i;
                max = number;
            }
            if ((number > 0) && (number < minPositive)){
                minPosNum = i;
                minPositive = number;
            }
        }
        if (number > 0){
            j ++;
            sumPositive = sumPositive + number;
        }
    }

    averageAll = static_cast<double>(sumAll) / i ;
    averPositive = static_cast<double>(sumPositive) / j ;

    std::cout << "Sum of all number: " << sumAll << '\n';
    std::cout << "Average all: " << averageAll << '\n';
    std::cout << "Average positive: " << averPositive << '\n';
    std::cout << "Max number: " << max << " and his number " << maxNumber << '\n';
    std::cout << "Min positive number : " << minPositive << " and his humber: " << minPosNum <<'\n';

    return 0;
}
 
