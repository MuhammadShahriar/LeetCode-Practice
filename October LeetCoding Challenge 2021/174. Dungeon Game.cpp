
int dp[213][213];

class Solution {
public:
    int calculateMinimumHP(vector<vector<int>>& a) {
        int m = a.size();
        int n = a[0].size();
        
        int l = -5e5, r = 5e5;
        int inf =  -100000000;
        int ans = -100000000;
        
        while (l <= r) {
            int mid = ( l + r ) / 2;
            for ( int i = 0; i < m; i++ ) {
                for ( int j = 0; j < n; j++ ) {
                    dp[i][j] = a[i][j];
                }
            }
            for ( int i = 0; i < m; i++ ) {
                for ( int j = 0; j < n; j++ ) {
                    if(i == j && i == 0) continue;
                    int ret = -100000000;
                    if ( j-1 >= 0 && dp[i][j-1] != inf ) ret = max ( ret, dp[i][j] + dp[i][j-1] );
                    if ( i-1 >= 0 && dp[i-1][j] != inf ) ret = max ( ret, dp[i][j] + dp[i-1][j] );
                    
                    if ( ret < mid ) ret = -100000000;
                    dp[i][j] = ret;
                    
                    //cout<<ret<<endl;
                }
            }
            
            if ( mid <= dp[m-1][n-1] ) {
                ans = max(mid, ans);
                l = mid+1;
            }
            else r = mid-1;
        }
        
        
        
        
        int ret = ans;
        
        if ( ret <= 0 ) {
            ret *= -1;
            ret++;
        }
        else {
            ret = 1;
        }
        
        if ( a[0][0] < 0 ) {
            a[0][0] *= -1;
            a[0][0]++;
            ret = max ( ret, a[0][0] );
        }
        
        return ret;
    }
};