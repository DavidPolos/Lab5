#include <iostream>
#include <map>
using namespace std;
#include <sstream>

struct gram_entry {
    int freq;
    map<char, int> trans_freq;
};

class Gram_map {
   public:
    Gram_map(int k) : k{k} {}

    void make_map(string s) {
        for (int i = 0; i < s.length() - k; ++i) {
            string gram = s.substr(i, k);
            gram_freq[gram][s[i + k]]++;
        }
    }

    void str() {
        for (auto& p : gram_freq) {
            cout << p.first << " :{ " << endl;
            for (auto& q : p.second) {
                cout << q.first << ": " << q.second << ", " << endl;
            }
            cout << "}" << endl;
        }
    }

   private:
    int k;
    map<string, map<char, int>> gram_freq;
};

int main() {
    Gram_map m{2};
    m.make_map("ababac");
    m.str();
}