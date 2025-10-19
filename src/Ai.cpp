#include "Ai.h"

Ai::Ai(int k) : k{k} {}

string Ai::generate(int length) {
    string output = model.first();

    for (int i = 0; i <= length - k - 1; ++i) {
        output += model.next(output.substr(i, k));
    }
    return output;
}

void Ai::train(string corpus) {
    if (corpus.length() >= k) {
        for (int i = 0; i < corpus.length() - k; ++i) {
            string gram = corpus.substr(i, k);
            char next = corpus[i + k];
            model.add(gram, next);
        }
    }
}
