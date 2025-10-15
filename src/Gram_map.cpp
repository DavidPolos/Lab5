#include "Gram_map.h"

#include <iostream>
#include <map>
using namespace std;

Gram_map::Gram_map(int k) : k{k} {}

void Gram_map::make_map(string s) {
    for (int i = 0; i < s.length() - k; ++i) {
        string gram = s.substr(i, k);
        gram_freq[gram].freq++;
        gram_freq[gram].trans_freq[s[i + k]]++;
    }
    condense();
}

string Gram_map::get_initial() {
    string out;
    int max = 0;
    for (auto& element : gram_freq) {
        if (element.second.freq > max) {
            max = element.second.freq;
            out = element.first;
        }
    }
    return out;
}

char Gram_map::next(string s) {
    return gram_freq[s].next;
}

void Gram_map::str() {
    for (auto& p : gram_freq) {
        cout << p.first << "," << p.second.freq << " : " << p.second.next << endl;
    }
}

void Gram_map::condense() {
    for (auto& element : gram_freq) {
        int max = 0;
        for (auto& trans_pair : element.second.trans_freq) {
            if (trans_pair.second > max) {
                max = trans_pair.second;
                element.second.next = trans_pair.first;
            }
        }
        element.second.trans_freq.clear();
    }
}
