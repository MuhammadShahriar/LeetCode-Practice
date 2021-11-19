class Solution {
public:
    int hammingDistance(int x, int y) {
        x ^= y;
        y = 0;
        for ( int i = 0; i < 32; i++ ) {
            if ( ( 1 << i ) & x ) y++;
        }
        
        
        return y;
    }
};