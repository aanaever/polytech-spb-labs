// Created by Anastasia

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

struct Record {
    string name;
    string phone;
};

class PhoneBook {
public:
    using iterator = vector<Record>::iterator;

    void addRecord(const Record& record) {
        records.push_back(record);
    }

    iterator begin() {
        return records.begin();
    }

    iterator end() {
        return records.end();
    }

    iterator next(iterator it) {
        return std::next(it);
    }

    iterator prev(iterator it) {
        return std::prev(it);
    }

    iterator insertRecord(iterator it, const Record& record, bool after = false) {
        if (after) {
            it = std::next(it);
        }
        return records.insert(it, record);
    }

    void replaceRecord(iterator it, const Record& record) {
        *it = record;
    }

    iterator moveNRecords(iterator it, int n) {
        int currentDistance;
        if (n > 0) {
            currentDistance = distance(it, end());
            if (currentDistance > n) {
                std::advance(it, n);
            } else {
                it = end();
            }
        } else {
            currentDistance = distance(begin(), it);
            if (currentDistance >= abs(n)) {
                advance(it, n);
            } else {
                it = begin();
            }
        }
        return it;
    }
    void print() const {
        for (const auto& record : records) {
            cout << record.name << " - " << record.phone << endl;
        }
    }

private:
    vector<Record> records;
};

int main() {
    PhoneBook phoneBook;

    phoneBook.addRecord({"Anna", "+7(912)577-0000"});
    phoneBook.addRecord({"Ivan", "+7(124)578-1111"});
    phoneBook.addRecord({"Misha", "+7(121)777-2222"});

    std::cout << "Phone book:" << std::endl;
    phoneBook.print();
    std::cout << std::endl;

    auto currentRecord = phoneBook.begin();

    cout << "Current contact: " << currentRecord->name << " - " << currentRecord->phone << endl;

    currentRecord = phoneBook.next(currentRecord);
    cout << "Next contact: " << currentRecord->name << " - " << currentRecord->phone << endl;

    currentRecord = phoneBook.prev(currentRecord);
    cout << "Previous contact: " << currentRecord->name << " - " << currentRecord->phone << endl;

    currentRecord = phoneBook.insertRecord(currentRecord, {"Olga", "+7(892)222-1230"}, false);
    cout << "Inserted contact (before): Olga - +7(892)222-1230" << endl;

    currentRecord = phoneBook.insertRecord(currentRecord, {"Eva", "+7(234)987-1562"}, true);
    cout << "Inserted contact (after): Eva - +7(234)987-1562" << endl;

    phoneBook.replaceRecord(currentRecord, {"Nadya", "+7(090)123-4567"});
    cout << "Replac contact: Nadya - +7(090)123-4567" << endl;

    phoneBook.addRecord({"Irina", "+7(123)456-789"});
    cout << "Add contact to the end: Irina - +7(123)456-789" << endl;

    int n = 2;
    currentRecord = phoneBook.moveNRecords(currentRecord, n);
    cout << "Move " << n << " records forward: " << currentRecord->name << " - " << currentRecord->phone << endl;

    n = -3;
    currentRecord = phoneBook.moveNRecords(currentRecord, n);
    cout << "Move " << abs(n) << " records backward: " << currentRecord->name << " - " << currentRecord->phone << endl;


    cout << endl << "Updated phone book:" << endl;
    phoneBook.print();

    return 0;
}

