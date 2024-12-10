#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include <algorithm>


using namespace std;

string formatText(const string& str) {
    string result;
    char prev = '\0';
    bool prev_space = false;

    for (const char& c : str) {
        if (isalnum(c)) {
            result += c;
            prev_space = false;
            prev = c;
        } else if (ispunct(c)) {
            if (prev == ' ') {
                result.pop_back();
            }
            result += c;
            prev_space = false;
            prev = c;
        } else if (isspace(c)) {
            if (!prev_space) {
                result += ' ';
                prev_space = true;
                prev = ' ';
            }
        }
    }

    if (isspace(result.front())) {
        result.erase(result.begin());
    }
    if (isspace(result.back())) {
        result.pop_back();
    }

    return result;
}


string replaceLongWords(string str) {
    string word;
    string result;
    istringstream iss(str);

    while (iss >> word) {
        if (word.length() > 10) {
            result += "Vau!!!";
        } else {
            result += word;
        }
        result += " ";
    }

    return result;
}

vector<string> splitText(const string& str, const int& lineLength) {
    vector<string> result;
    string line;
    istringstream iss(str);
    string word;

    while (iss >> word) {
        if (line.length() + word.length() > lineLength) {
            result.push_back(line);
            line = word + " ";
        } else {
            line += word + " ";
        }
    }

    result.push_back(line);

    return result;
}

int main() {

 
    ifstream inFile("input.txt");

    /*if (!inFile.is_open()) {
        cerr << "Unable to open file." << endl;
        return 1;
    } */

    string inputText((istreambuf_iterator<char>(inFile)), istreambuf_iterator<char>());
    inFile.close();

    string formattedText = formatText(inputText);

    string finalText = replaceLongWords(formattedText);

    vector<string> lines = splitText(finalText, 40);

    for (const auto& line : lines) {
        cout << line << endl;
    }

    return 0;
}
