
long long nCr[40][20];
long long calc ( int n, int r )
{
    if ( r == 1 ) return n;
    if ( n == r ) return 1;
    if ( nCr[n][r] != -1 ) return nCr[n][r];
    
    return nCr[n][r] = calc ( n-1, r-1 ) + calc ( n-1, r );
}

class Solution {
public:
    int numTrees(int n) {
        memset ( nCr, -1, sizeof(nCr) );
        long long v = calc ( 2*n, n );
        v /= (n+1);
        return (int)v;
    }
};