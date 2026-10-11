#include <string>
#include <vector>
#include <numeric>

using namespace std;

class Solution {
public:
    int numDistinct(string s, string t) {
        int m = t.length();
        int n = s.length();
        vector<double> dp(m + 1, 0);
        dp[0] = 1;

        for (int j = 1; j <= n; ++j) {
            for (int i = m; i >= 1; --i) {
                if (t[i - 1] == s[j - 1]) {
                    dp[i] += dp[i - 1];
                }
            }
        }

        return (int)dp[m];
    }
};