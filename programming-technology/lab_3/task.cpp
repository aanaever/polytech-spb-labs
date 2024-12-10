#include <iostream>
#include <cctype>
#include <string>
#include <fstream>

char *merge_charStrings(char *cdestination, const char *csource, const char *csource2) {
    int i = 0;
    int count = 0;

    while(csource[i]){
        cdestination[i] = csource[i];
        i++;
        count++;
    }
    i = 0;
    while (csource2[i]!= '\0') {
            if ((isdigit(csource2[i])) != 0) {
                *(cdestination + count) = *(csource2 + i);
                count++;
            }
            i++;
        }

    cdestination[count+1] = '\0';
    return cdestination;
}

int main() {
    const int MAX_N_STRING = 50;

    std::ifstream inputFile("C:\\Users\\Hokage\\Desktop\\data.txt");
    char *lengthString = new char[MAX_N_STRING];

    
    inputFile.getline(lengthString, MAX_N_STRING);
    int N = std::stoi(lengthString); 
    char *source = new char[N + 1]; 
    inputFile.getline(source, N + 1); 

    inputFile.getline(lengthString, MAX_N_STRING);
    int M = std::stoi(lengthString);
    char *source2 = new char[M + 1];
    inputFile.getline(source2, M + 1);

    std::cout << "First string in C style: " << source << std::endl;
    std::cout << "Second string in C style: " << source2 << std::endl;
    char *destination = new char[MAX_N_STRING + 3];

    std::cout << merge_charStrings(destination, source, source2) << std::endl<< std::endl;
    //std::cout << merge_Strings(dest,stringPhrase, stringPhrase2) << std::endl<< std::endl;

    delete[] source;
    delete[] source2;
    delete[] destination;
    delete[] lengthString;
    inputFile.close();

    return 0;
}

