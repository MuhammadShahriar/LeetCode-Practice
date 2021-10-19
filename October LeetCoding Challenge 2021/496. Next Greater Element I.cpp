const int mx = 1e4+123;
int id[mx];

class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        for ( int i = 0; i < nums2.size(); i++ ) {
            id[nums2[i]] = i;
        }
        
        vector<int> ans;
        
        for ( auto u : nums1 ) {
            int j = id[u];
            bool done = 0;
            
            for ( int i = j+1; i < nums2.size(); i++ ) {
                if ( nums2[i] > u ) {
                    ans.push_back ( nums2[i] );
                    done = 1;
                    break;
                }
            }
            
            if ( !done ) ans.push_back ( -1 );
        }
        
        return ans;
    }
};