#include <iostream>
#include <map>
using namespace std;
#include <fstream>
#include <random>
#include <regex>
#include <sstream>

#include "Ai.h"

int main(int argc, char* argv[]) {
    if (argc == 4) {
        ifstream file(argv[2]);
        if (!file) {
            cerr << "Could not open file \n";
        }
        Ai ai{atoi(argv[1])};
        stringstream stream;

        stream << file.rdbuf();

        ai.train(stream.str());
        cout << ai.generate(atoi(argv[3])) << endl;
    }
}