#include "Ai.h"

Ai::Ai(int k) : model{k}, k{k} {}

string Ai::generate(int length) {
    string output = model.get_initial();

    for (int i = 0; i <= length - k - 1; ++i) {
        output += model.next(output.substr(i, k));
    }
    return output;
}

void Ai::train(string corpus) {
    model.make_map(corpus);
}
