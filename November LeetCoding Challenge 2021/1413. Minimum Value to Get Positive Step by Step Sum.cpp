class Solution {
public:
    int minStartValue(vector<int>& nums) {
        int l = 1, r = 1e4+123, ans = 1e4+123;
        
        while ( l <= r ) {
            int mid = ( l + r ) >> 1;
            int tmp = mid;
            
            bool done = 1;
            for ( auto u : nums ) {
                mid += u;
                if ( mid < 1 ) {
                    done = 0;
                    break;
                }
            }
            
            if ( done ) {
                ans = min ( ans, tmp );
                r = tmp-1;
            }
            else l = tmp+1;
        }
        
        return ans;
    }
};