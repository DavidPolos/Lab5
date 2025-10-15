#include <iostream>
#include <map>
using namespace std;
#include <random>
#include <sstream>

#include "Ai.h"

int main() {
    Ai a{3};
    a.train("ababcbababcabacba");
    cout << a.generate(20) << endl;
}