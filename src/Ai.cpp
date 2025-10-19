#include "Ai.h"

Ai::Ai(int k) : model{k} {}

string Ai::generate(int length) {
    string output = model.first();

    for (int i = 0; i <= length - model.get_k() - 1; ++i) {
        output += model.next(output.substr(i, model.get_k()));
    }
    return output;
}

void Ai::train(string corpus) {
    if (corpus.length() >= model.get_k()) {
        for (int i = 0; i < corpus.length() - model.get_k(); ++i) {
            string gram = corpus.substr(i, model.get_k());
            char next = corpus[i + model.get_k()];
            model.add(gram, next);
        }
    }
}
