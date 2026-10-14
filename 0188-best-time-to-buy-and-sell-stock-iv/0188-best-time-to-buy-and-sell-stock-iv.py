class Solution(object):
    def maxProfit(self, k, prices):
        """
        :type k: int
        :type prices: List[int]
        :rtype: int
        """
        if not prices or k == 0:
            return 0
        
        # If k is large enough, treat it as unlimited transactions
        if k >= len(prices) // 2:
            return sum(max(prices[i] - prices[i - 1], 0) for i in range(1, len(prices)))
        
        buy = [-float('inf')] * (k + 1)
        sell = [0] * (k + 1)
        
        for price in prices:
            for j in range(1, k + 1):
                buy[j] = max(buy[j], sell[j - 1] - price)
                sell[j] = max(sell[j], buy[j] + price)
                
        return sell[k]