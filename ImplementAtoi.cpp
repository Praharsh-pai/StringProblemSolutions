#include <iostream>
#include <climits>
#include <cstring>
using namespace std;

class Solution {
  public:
    int myAtoi(char *s) {
        int i = 0;
        int sign = 1;
        long result = 0;
        while (s[i] == ' ') {
            i++;
        }
        if (s[i] == '-') {
            sign = -1;
            i++;
        } else if (s[i] == '+') {
            i++;
        }
        while (s[i] >= '0' && s[i] <= '9') {
            result = result * 10 + (s[i] - '0');
            if (sign == 1 && result > INT_MAX) {
                return INT_MAX;
            } else if (sign == -1 && -result < INT_MIN) {
                return INT_MIN;
            }
            i++;
        }
        return (int)(sign * result);
    }
};
int main() {
    Solution sol;
    char input1[] = "-123";
    cout << "Input: \"" << input1 << "\" -> Output: " << sol.myAtoi(input1) << endl;
    return 0;
}