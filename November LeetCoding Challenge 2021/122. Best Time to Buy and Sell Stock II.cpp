


class Solution {
public:
    int maxProfit(vector<int>& a) {
        int n = a.size(), cur0, cur1, prev0, prev1;
        
        cur0 = prev0 = 0;
        cur1 = prev1 = -a[0];
        
        for ( int i = 1; i < n; i++ ) {
            cur0 = max ( prev1 + a[i], prev0 );
            cur1 = max ( prev0 - a[i], prev1 );
            prev0 = cur0;
            prev1 = cur1;
        }
        
        return max ( cur0, cur1 );
    }
};