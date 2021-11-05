class Solution {
public:
    int arrangeCoins(int n) {
        if(n==1) return 1;
        for ( int i = 1; i <= n; i++ ) {
            long long sum = ( 1LL * i * (i+1) ) >> 1;
            if ( n < sum ) return i-1;
        }
        
        return 0;
    }
};