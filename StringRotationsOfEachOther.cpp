#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
  public:
    vector<int> computeLPS(string &pattern) {
        int n = pattern.length();
        vector<int> lps(n, 0);
        int len = 0;
        for (int i = 1; i < n; ++i) {
            while (len > 0 && pattern[i] != pattern[len])
                len = lps[len - 1];
            if (pattern[i] == pattern[len])
                lps[i] = ++len;
        }
        return lps;
    }
    bool kmpSearch(string &text, string &pattern) {
        int n = text.length(), m = pattern.length();
        vector<int> lps = computeLPS(pattern);
        int i = 0, j = 0;

        while (i < n) {
            if (text[i] == pattern[j]) {
                ++i; ++j;
                if (j == m) return true;
            } else {
                if (j != 0)
                    j = lps[j - 1];
                else
                    ++i;
            }
        }
        return false;
    }
    bool areRotations(string &s1, string &s2) {
        if (s1.length() != s2.length()) return false;
        string temp = s1 + s1;
        return kmpSearch(temp, s2);
    }
};
int main() {
    Solution sol;
    string s1 = "abcd", s2 = "cdab";
    cout << (sol.areRotations(s1, s2) ? "true" : "false") << endl;
    return 0;
}