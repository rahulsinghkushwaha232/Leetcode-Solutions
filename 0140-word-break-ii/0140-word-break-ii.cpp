class Solution {
private:
    unordered_map<string, vector<string>> memo;

    vector<string> dfs(string s, unordered_set<string>& wordSet) {
        if (memo.find(s) != memo.end()) {
            return memo[s];
        }
        
        vector<string> result;
        if (s.empty()) {
            result.push_back("");
            return result;
        }

        for (int i = 1; i <= s.length(); ++i) {
            string prefix = s.substr(0, i);
            if (wordSet.count(prefix)) {
                vector<string> suffixes = dfs(s.substr(i), wordSet);
                for (const string& suffix : suffixes) {
                    result.push_back(prefix + (suffix.empty() ? "" : " ") + suffix);
                }
            }
        }

        return memo[s] = result;
    }

public:
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> wordSet(wordDict.begin(), wordDict.end());
        memo.clear();
        return dfs(s, wordSet);
    }
};