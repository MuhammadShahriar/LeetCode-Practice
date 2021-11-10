class Solution(object):
    def maxProfit(self, prices):
        cur0 = prev0 = 0
        cur1 = prev1 = -prices[0]
        
        for i in range ( 1, len(prices) ) :
            cur0 = max ( prev1 + prices[i], prev0 )
            cur1 = max ( prev0 - prices[i], prev1 );
            
            prev0 = cur0
            prev1 = cur1
        
        return max ( cur0, cur1 )