//
// Created by Hokage on 18.10.2022.
//

#include <iostream>
#include <cmath>

bool isNumberOfIteration(int iteration, int nMax){
    if (iteration > nMax){
        throw std::runtime_error("nMax error!");
    }else {
        return true;
    }
}

double calculateSum(double x, double  absError, int nMax){
    double sum = 1.0;
    double mul = 1.0;
    int iteration = 0;
    double numerator = 1;
    double denominator = 2;

    while (std::abs(mul) > absError && isNumberOfIteration(iteration, nMax)){
        mul *= -(numerator / denominator) * x;
        sum += mul;
        numerator += 2.0;
        denominator += 2.0;
        iteration ++;
    }
    return sum;
}

void calculateInterval(double beginInterval,double endInterval, double step, double absError){
    const int nMax = 1000000000;

    if (beginInterval <= -1.0 || endInterval  >= 1.0){
        throw std::runtime_error(" interval error");
    }

    double x = (-1.0 + step);
    double result = 0.0;

    while (x >= beginInterval && x <= endInterval){
        try{
            result = calculateSum(x, absError, nMax);
            std::cout << " Number = " << x << " Sum = " << result << " Cmath = " << 1.0 / sqrt(1 + x) << std::endl;
        }catch (const std::runtime_error &e) {
            std::cerr << e.what() << std::endl;
        }
        x += step;
    }
}

int main(){

    double beginiNterval;
    std::cout << "Enter begin interval: ";
    std::cin >> beginiNterval;
    double endInterval;
    std::cout << "Enter end interval: ";
    std::cin >> endInterval;
    double step;
    std::cout << "Enter step: ";
    std::cin >> step;
    double error;
    std::cout << "Enter error: ";
    std::cin >> error;

    calculateInterval(beginiNterval, endInterval, step, error);


    return 0;
}
