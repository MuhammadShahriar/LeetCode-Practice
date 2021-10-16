const int MAXN = 1e5+5;
long long arr[MAXN];
const int LOG = log2(MAXN) + 1;
long long sp[MAXN][20];
int prelog[MAXN];
int N;

void init_log() 
{ //O(MAXN)
    prelog[1] = 0;
    for( int i = 2; i < MAXN; ++i ) prelog[i] =
    prelog[i/2] + 1;
}

void init() { //O(NlogN)
    for( int i = 0; i < N; ++i ) sp[i][0] = arr[i];
    for( int j = 1; j <= LOG; ++j )
    for( int i = 0; i + (1 << j) <= N; ++i )
        sp[i][j] = max(sp[i][j-1], sp[i + (1 << (j - 1))][j - 1]);
    }

long long query(int L, int R) { //O(1)
    int j = prelog[R - L + 1];
    long long minimum = max(sp[L][j], sp[R - (1 << j) + 1][j]);
    return minimum;
}

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<long long> dp1(n);
        
        int mn = prices[0];
        for ( int i = 1; i < n; i++ ) {
            dp1[i] = max ( 0, prices[i] - mn );
            mn = min ( mn, prices[i] );
        }
        
        for ( int i = 0; i < n; i++ ) arr[i] = dp1[i];
        N = n;
        
        init_log();
        init();
        
        long long ans = 0;
        int mx = prices[n-1];
        for ( int i = n-2; i >= 0; i-- ) {
            
            long long a = mx - prices[i];
            mx = max ( mx, prices[i] );
            long long d = 0;
            if ( i-2 >= 0 ) d = query(0, i-1);
            ans = max ( ans, a + d );
        }
        
        return ans;
    }
};