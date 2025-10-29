#include "Gram_map.h"

#include <iostream>
using namespace std;

void Gram_map::add(string gram, char c) {
    gram_freq[gram].freq++;
    gram_freq[gram].trans_freq[c]++;
}

char Gram_map::next(string s) {
    /*Finds the character that comes after 's' by either getting it directly
    if it has not been accessed before or searching for the most frequently
    appearing character in trans_freq.
    */
    if (gram_freq[s].next) {
        return gram_freq[s].next;
    }
    int max = 0;
    for (auto& trans_freq : gram_freq[s].trans_freq) {
        if (trans_freq.second > max) {
            max = trans_freq.second;
            gram_freq[s].next = trans_freq.first;
        }
    }
    gram_freq[s].trans_freq.clear();
    return gram_freq[s].next;
}

string Gram_map::first() {
    /*This solution is in replacement of a more thorough Gram_map implementation
    where a user could iterate over the datastructure and find the most frequent one by
    themselves.
    */
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
