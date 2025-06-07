#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

class Solution {
  public:
    string addBinary(string& s1, string& s2) {
        int i = s1.size() - 1;
        int j = s2.size() - 1;
        int carry = 0;
        string result = "";
        while (i >= 0 || j >= 0 || carry) {
            int sum = carry;
            if (i >= 0) {
                sum += s1[i] - '0';
                i--;
            }
            if (j >= 0) {
                sum += s2[j] - '0';
                j--;
            }
            result += (sum % 2) + '0';
            carry = sum / 2;
        }
        reverse(result.begin(), result.end());
        int first_non_zero = 0;
        while (first_non_zero < result.size() && result[first_non_zero] == '0') {
            first_non_zero++;
        }
        if (first_non_zero == result.size()) return "0"; // all zeros
        return result.substr(first_non_zero);
    }
};
int main() {
    Solution sol;
    string s1 = "1101";
    string s2 = "111";
    cout << "Input: s1 = \"" << s1 << "\", s2 = \"" << s2 << "\"\n";
    cout << "Output: " << sol.addBinary(s1, s2) << endl;
    return 0;
}