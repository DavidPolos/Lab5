#include <iostream>
#include <map>
using namespace std;
#include <sstream>

struct Gram_entry {
    int freq;
    map<char, int> trans_freq;
    char next;
};

class Gram_map {
   public:
    Gram_map(int k) : k{k} {}

    void make_map(string s) {
        for (int i = 0; i < s.length() - k; ++i) {
            string gram = s.substr(i, k);
            gram_freq[gram].freq++;
            gram_freq[gram].trans_freq[s[i + k]]++;
        }
        condense();
    }

    string get_initial() {
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

    char next(string s) {
        return gram_freq[s].next;
    }

    void str() {
        for (auto& p : gram_freq) {
            cout << p.first << "," << p.second.freq << " : " << p.second.next << endl;
        }
    }

   private:
    int k;
    map<string, Gram_entry> gram_freq;

    void condense() {
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
};

int main() {
    Gram_map m{2};
    m.make_map("ababacbacbaabbacba");
    m.str();
    cout << m.get_initial() << endl;
    cout << m.next("ac");
}