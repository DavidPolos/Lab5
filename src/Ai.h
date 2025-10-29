#include <iostream>
#include "Gram_map.h"

class Ai {
   public:
    Ai(int k);

    void train(string corpus);

    string generate(int length);

   private:
    Gram_map model;
    int k;
};