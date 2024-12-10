//2.

#include <iostream>
#include <list>
#include <random>

using namespace std;

void printList(const list<int>& list) {
    auto begin = list.begin();
    auto end = list.end();
    end--;

    while (begin != end) {
        cout << *begin++ << " " << *end-- << " ";
        if (begin == end) { 
            cout << *begin;
            break;
        } else if (std::distance(begin, end) == 1) { 
            cout << *begin << " " << *end;
            break;
        }
    }

    cout << endl;
}

void fillList(list<int>& list, int x) {
   // list.clear(); 

    for (int i = 0; i < x; i++) {
        int random_number = rand() % 20 + 1; 
        list.push_back(random_number); 
    }
}

int main() {
    list<int> mylist;
    int x = 14;

    fillList(mylist, x);

    /*srand(time(0));

    int list_size = rand() % 21;
    for (int i = 0; i < list_size; i++) {
        mylist.push_back(rand() % 20 + 1);
    } */

    cout << "List of " << x << "elements: ";
    for (auto it = mylist.begin(); it != mylist.end(); ++it) {
        cout << *it << " ";
    }
    std::cout << std::endl;

    std::cout << "Print list in a special otder  ";
    printList(mylist);

    return 0;
}
