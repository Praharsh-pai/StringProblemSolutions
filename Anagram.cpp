#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
  public:
    bool areAnagrams(string& s1, string& s2) {
        if (s1.length() != s2.length())
            return false;
        vector<int> count(26, 0);
        for (int i = 0; i < s1.length(); ++i) {
            count[s1[i] - 'a']++;
            count[s2[i] - 'a']--;
        }
        for (int c : count) {
            if (c != 0)
                return false;
        }
        return true;
    }
};
int main() {
    Solution sol;
    string s1 = "geeks", s2 = "kseeg";
    cout << "Input: s1 = \"" << s1 << "\", s2 = \"" << s2 << "\"\n";
    cout << "Output: " << (sol.areAnagrams(s1, s2) ? "true" : "false") << endl;
    return 0;
}