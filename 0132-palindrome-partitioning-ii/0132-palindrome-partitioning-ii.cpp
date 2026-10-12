class Solution {
public:
    int minCut(string s) {
        int n = s.length();
        vector<int> cuts(n);
        vector<vector<bool>> palindrome(n, vector<bool>(n, false));

        for (int i = 0; i < n; ++i) {
            int min_cuts = i;
            for (int j = 0; j <= i; ++j) {
                if (s[j] == s[i] && (i - j <= 2 || palindrome[j + 1][i - 1])) {
                    palindrome[j][i] = true;
                    if (j == 0) {
                        min_cuts = 0;
                    } else {
                        min_cuts = min(min_cuts, cuts[j - 1] + 1);
                    }
                }
            }
            cuts[i] = min_cuts;
        }
        return cuts[n - 1];
    }
};