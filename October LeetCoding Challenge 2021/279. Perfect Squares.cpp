
const int mx = 1e4+123;
int dp[123][mx], num, sq;

long long solve ( long long i, long long val )
{
    if ( val > num ) return 10000;
    if ( val == num ) return 0;
    if ( i > sq ) return 10000;
    if ( dp[i][val] != -1 ) return dp[i][val];
    
    int ret1 = 0, ret2 = 0, ret3 = 0;
    ret1 = 1 + solve (i, val + (i*i) );
    ret2 = 1 + solve ( i+1, val + ( ( i+1 ) * ( i+1 ) ) );
    ret3 = solve ( i+1, val );
                      
    return dp[i][val] = min ( {ret1, ret2, ret3} );
}


class Solution {
public:
    int numSquares(int n) {
        num = n;
        sq = sqrt(n)+1;
        for ( int   i = 0; i <= sq; i++ ) {
            for ( int j = 0; j <= n; j++ ) dp[i][j] = -1;
        }
        return solve ( 1, 0 );
    }
};