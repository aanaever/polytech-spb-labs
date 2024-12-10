
#include <iostream>
#include <vector>
#include <algorithm>
#include <random>

using namespace std;


class StatisticFunctor {
public:
    void operator()(int number) {
        max = std::max(max, number); 
        min = std::min(min, number); 
        sum += number;
        if (number > 0) {
            ++positive; 
        } else if (number < 0) {
            ++negative; 
        }
        if (number % 2 == 0) {
            even += number;
        } else {
            odd += number; 
        }
        if (counter == 0) {
            first = number;
        }
        last = number;
        ++counter;
    }

    void print_statistics() const {
        cout << "Max number: " << max << endl;
        cout << "Min number: " << min << endl;
        cout << "Average number: " << static_cast<double>(sum) / counter << endl;
        cout << "Positive numbers count: " << positive << endl;
        cout << "Negative numbers count: " << negative << endl;
        cout << "Odd numbers sum: " << odd << endl;
        cout << "Even numbers sum: " << even << endl;
        cout << "First and last numbers match: " << (first == last ? "Yes" : "No") << endl;
    }
private:
    int max = std::numeric_limits<int>::min();
    int min = std::numeric_limits<int>::max();
    int sum = 0;
    int positive = 0;
    int negative = 0;
    int even = 0;
    int odd = 0;
    int counter = 0;
    int first = 0;
    int last = 0;
};

int main() {
 
    int length = 10;
    vector<int> seq(length);
    generate(seq.begin(), seq.end(), []() { return rand() % 1000 - 500; });

   cout << "Generated sequence: ";
    for (int i = 0; i < length; ++i) {
        cout << seq[i] << " ";
    }
    cout << endl;

    StatisticFunctor statistic = for_each(seq.begin(), seq.end(), StatisticFunctor());
    statistic.print_statistics();

    return 0;
}
