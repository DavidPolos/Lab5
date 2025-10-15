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

class Ai {
   public:
    Ai(int k) : model{k}, k{k} {}

    string generate(int length) {
        string output = model.get_initial();

        for (int i = 0; i <= length - k - 1; ++i) {
            cout << output << endl;
            output += model.next(output.substr(i, k));
        }
        return output;
    }

    void train(string corpus) {
        model.make_map(corpus);
    }

   private:
    Gram_map model;
    int k;
};

int main() {
    Ai a{3};
    a.train("ababcbababcabacba");
    cout << a.generate(20);
}