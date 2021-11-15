class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        sort ( nums.begin(), nums.end() );
        int n = nums.size();
        vector<int> dp(n, -1), child(n, -1);
        int mx = -1, cur = -1;
        
        for ( int i = 0; i < n; i++ ) {
            for ( int j = i+1; j < n; j++ ) {
                if ( nums[j] % nums[i] == 0 ) {
                    if ( dp[j] < 1 + dp[i] ) {
                        dp[j] = 1 + dp[i];
                        child[j] = i;
                        if ( dp[j] > mx ) {
                            mx = dp[j];
                            cur = j;
                        }
                    }
                }
            }
        }
        
        vector<int> ans;
        
        while ( cur != -1 ) {
            ans.push_back ( nums[cur] );
            cur = child[cur];
        }
        
        if ( ans.empty() ) ans.push_back(nums[0]);
        
        return ans;
    }
};