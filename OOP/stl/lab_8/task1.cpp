//1
#include <iostream>
#include <list>
#include <algorithm>

using namespace std;

class PIMultiply {
public:
    void operator()(double& number) const {
        number *= 3.1415926535;
    }
};

int main() {
    list<double> numbers = {1.0, 2.0, 3.0, 4.0, 5.0};

    for_each(numbers.begin(), numbers.end(), PIMultiply());

    for (const auto& num : numbers) {
        cout << num << " ";
    }
    cout << endl;
    return 0;
}
