class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans;
        sort ( nums.begin(), nums.end() );
        
        map<int,int> m;
        for ( int i = 0; i < nums.size(); i++  ) m[nums[i]] = i;
        
        for ( int i = 0; i < nums.size(); i++ ) {
            if ( i-1 >= 0 && nums[i] == nums[i-1] ) continue;
            for ( int j = i+1; j < nums.size(); j++ ) {
                if ( j-1 >= i+1 && nums[j] == nums[j-1] ) continue;
                int d = -(nums[i] + nums[j]);
                if ( m[d] > j ) {
                    vector<int> v = {nums[i], nums[j], d};
                    sort (v.begin(), v.end());
                    
                    ans.push_back (v);
                }
            }
        }
        
        
        return ans;
    }
};