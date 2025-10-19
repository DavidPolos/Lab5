
#include <iostream>
#include <map>
using namespace std;

class Gram_map {
   private:
    struct Gram_entry {
        int freq;
        map<char, int> trans_freq;
        char next;
    };

    map<string, Gram_entry> gram_freq;

   public:
    void add(string gram, char c);

    char next(string s);

    string first();
};
