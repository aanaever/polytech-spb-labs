#include <iostream>

#include <cctype>
#include <fstream>
#include <algorithm>


char *mergeCharStrings(char *destination, const char *source, const char *source2) {
    int i = 0;
    int count = 0;

    while (source[i]) {  
        destination[i] = source[i];
        i++;
        count++;
    }
    i = 0;
    while (source2[i] != '\0') {
        if ((isdigit(source2[i])) != 0) {
            *(destination + count) = *(source2 + i);
            count++;
        }
        ++i;
    }
    *(destination + count) = '\0'; 
    return destination;
}

std::string mergeStrings(const std::string &source, const std::string &source2) {
    std::string destination = source;
    for (int i = 0; i < source2.size(); ++i) {
        if ((isdigit(source2[i])) != 0) {
            destination += source2[i];
        }
    }

    return destination;
}


int main() {
    int MAX_N_STRING = 0;

    std::ifstream inputFile;
    inputFile.open("path");

    while (!inputFile.eof()) {

        inputFile >> MAX_N_STRING;

        if (MAX_N_STRING == 0) {
            break;
        }
        char *source = new char[MAX_N_STRING + 1];
        char *source2 = new char[MAX_N_STRING + 1];
        inputFile.ignore();

        inputFile.getline(source, MAX_N_STRING + 1);

        inputFile.getline(source2, MAX_N_STRING + 1);


        char *destination = new char[MAX_N_STRING * 2];

        std::cout << "First string in C style: " << source << std::endl;
        std::cout << "Second string in C style: " << source2 << std::endl;


        std::cout << "Method in C style: " << mergeCharStrings(destination, source, source2) << std::endl;

        std::string sourceString = source;
        std::string sourceString2 = source2;
        std::string destinationString = destination;
        std::cout << "Method in String style: " << mergeStrings(sourceString, sourceString2)
                  << std::endl;

        delete[] source;
        delete[] source2;
        delete[] destination;
        MAX_N_STRING = 0;

    }

    inputFile.close();

    return 0;
}
