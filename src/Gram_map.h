
#include <iostream>
#include <map>
using namespace std;

struct Gram_entry;

class Gram_map {
   private:
    struct Gram_entry {
        int freq;
        map<char, int> trans_freq;
        char next;
    };

    int k;
    map<string, Gram_entry> gram_freq;

    void condense();

   public:
    Gram_map(int k);

    void make_map(string s);

    string get_initial();

    char next(string s);

    void str();
};