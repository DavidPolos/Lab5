#include <iostream>

#include "Gram_map.h"

class Ai {
   public:
    Ai(int k) : model{k} {};

    void train(string corpus);

    string generate(int length);

   private:
    Gram_map model;
};