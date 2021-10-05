int dp[50], n;

int solve ( int i )
{
    if ( i > n ) return 0;
    if ( i == n ) return 1;
    if ( dp[i] != -1 ) return dp[i];
    
    return dp[i] = solve ( i+1 ) + solve ( i+2 );
}

class Solution {
public:
    int climbStairs(int val) {
        n = val;
        memset ( dp, -1, sizeof(dp) );
        
        return solve ( 0 );
    }
};