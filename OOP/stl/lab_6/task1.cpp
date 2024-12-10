//1
#include <iostream>
#include <fstream>
#include <string>
#include <unordered_set>


using namespace std;
int main() {
    string filename = "C://Users//Hokage//Desktop//example.txt";
    ifstream infile(filename); 

    if (!infile.is_open()) {
        cerr << "Failed to open " << filename << endl;
        return 1;
    }

    unordered_set<string> words; 
    //set<string> words;
    string word;
    while (infile >> word) { 
        words.insert(word); 
    }

    for (const auto& word : words) {
        cout << word << endl;
    }
    return 0;
}





