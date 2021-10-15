const int mx = 5e3+123;
int dp[mx][1123][3], n;
vector<int> a;

int solve ( int i, int v, int f1 )
{
    if ( i >= n ) return 0;
    if ( dp[i][v][f1] != -1 ) return  dp[i][v][f1];
    
    int ret1 = 0, ret2 = 0;
    ret1 = solve ( i+1, v, f1 );
    if ( f1 == 0 ) ret2 = solve ( i+1, a[i], 1 );
    else ret2 = a[i] - v + solve ( i+2, 0, 0 );
    
    return dp[i][v][f1] = max ( ret1, ret2 );
}


class Solution {
public:
    int maxProfit(vector<int>& prices) {
        a = prices;
        n = a.size();
        int Mx = *max_element(a.begin(), a.end());
        for(int i = 0; i < n; i++) {
            for ( int j = 0; j <= Mx; j++ ) {
                dp[i][j][0] = dp[i][j][1] = -1;
            }
        }
        return solve ( 0, 0, 0 );
    }
};