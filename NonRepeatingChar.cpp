#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
  public:
    char nonRepeatingChar(string &s) {
        vector<int> freq(26, 0);
        for (char ch : s) {
            freq[ch - 'a']++;
        }
        for (char ch : s) {
            if (freq[ch - 'a'] == 1) {
                return ch;
            }
        }
        return '$';
    }
};
int main() {
    Solution sol;
    string s1 = "geeksforgeeks";
    cout << "Input: \"" << s1 << "\" -> Output: " << sol.nonRepeatingChar(s1) << endl;
    return 0;
}