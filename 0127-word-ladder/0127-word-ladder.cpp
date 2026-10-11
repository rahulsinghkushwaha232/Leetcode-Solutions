#include <string>
#include <vector>
#include <unordered_set>
#include <queue>

using namespace std;

class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> wordSet(wordList.begin(), wordList.end());
        if (wordSet.find(endWord) == wordSet.end()) {
            return 0;
        }

        queue<string> q;
        q.push(beginWord);

        int level = 1;

        while (!q.empty()) {
            int size = q.size();
            for (int i = 0; i < size; ++i) {
                string curr = q.front();
                q.pop();

                if (curr == endWord) {
                    return level;
                }

                for (int j = 0; j < curr.length(); ++j) {
                    char originalChar = curr[j];

                    for (char c = 'a'; c <= 'z'; ++c) {
                        curr[j] = c;

                        if (wordSet.find(curr) != wordSet.end()) {
                            wordSet.erase(curr);
                            q.push(curr);
                        }
                    }

                    curr[j] = originalChar;
                }
            }
            level++;
        }

        return 0;
    }
};