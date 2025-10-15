#include <iostream>

#include "Gram_map.h"

class Ai {
   public:
    Ai(int k);

    string generate(int length);

    void train(string corpus);

   private:
    Gram_map model;
    int k;
};