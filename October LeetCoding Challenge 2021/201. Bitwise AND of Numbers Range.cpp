
long long cntBit ( long long n, int i )
{
    long long d = 1 << i;
    n++;
    long long one = ( n / (d*2) ) * d;
    if ( n % (d*2) >= d) one += ( n % (d*2) ) - d;
    
    return one;
}

class Solution {
public:
    int rangeBitwiseAnd(long long left, long long right) {
        int ans = 0;
        for ( int i = 0; i < 31; i++ ) {
            long long l = cntBit ( left-1, i );
            long long r = cntBit ( right, i );
            if ( r - l == right - left + 1 ) ans = ans | ( 1 << i );
        }
        
        return ans;
    }
};