#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int buy1 = INT_MAX, sell1 = 0;
        int buy2 = INT_MAX, sell2 = 0;

        for (int price : prices) {
            buy1 = min(buy1, price);
            sell1 = max(sell1, price - buy1);
            buy2 = min(buy2, price - sell1);
            sell2 = max(sell2, price - buy2);
        }

        return sell2;
    }
};