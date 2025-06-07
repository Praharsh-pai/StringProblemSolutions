#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

class Solution {
  public:
    int minChar(string& s) {
        string rev = s;
        reverse(rev.begin(), rev.end());
        string combined = s + "#" + rev;
        int n = combined.size();
        vector<int> lps(n, 0);
        for (int i = 1; i < n; ++i) {
            int len = lps[i - 1];
            while (len > 0 && combined[i] != combined[len]) {
                len = lps[len - 1];
            }
            if (combined[i] == combined[len]) {
                len++;
            }
            lps[i] = len;
        }
        return s.length() - lps[n - 1];
    }
};
int main() {
    Solution sol;
    string s1 = "abc";
    cout << "Input: \"" << s1 << "\" -> Output: " << sol.minChar(s1) << endl;
    return 0;
}