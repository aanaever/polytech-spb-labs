#include <iostream>

double func(double x){
    return x * x;
}

double integrateRectangle(double a, double b, int n){
    if (n <= 0){
        throw std::runtime_error("Error! Expression must be positive");
    }
    double res = 0.0;
    double step = (b - a) / n;
    for (int i = 0; i < n; ++i) {
        res += func(a + step * (i + 0.5));
    }
    return res * step;
}

double integrate(double a, double b, int n, double error) {
    if (error <= 0){
        throw std::invalid_argument("Error should be positive");
    }
    const double RUNGE = 1.0 / 3.0;
    double res1 = integrateRectangle(a, b, n);
    int n2 = n * 2;
    double res2 = integrateRectangle(a, b, n2);
    while (abs(res2 - res1) * RUNGE > error){
        res1 = res2;
        n = n2;
        n2 *= 2;
        res2 = integrateRectangle(a, b, n2);
    }
    return res2;
}

int main() {
    double a;
    std::cout << "Enter lower bound: ";
    std::cin >> a;
    double b;
    std::cout << "Enter upper bound: ";
    std::cin >> b;
    double error;
    std::cout << "Enter error: ";
    std::cin >> error;
    int n;
    std::cout << "Enter start count: ";
    std::cin >> n;

    std::cout << "Result: " << integrate(a, b, n, error) << '\n';
    return 0;
}
