class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        
        vector<int> sum(n+3);
        
        sum[n-1] = 1;
        for ( int i = n-2; i >= 0; i-- ) {
            int l = min (n-1, i+nums[i]);
            int r = i+1;
            
            int s = sum[r] - sum[l+1];
            
            if (s > 0) sum[i] = 1 + sum[i+1];
            else sum[i] = sum[i+1];
            //cout << i << " " << sum[i] << endl;
        }
        
        int l = min (n-1, 0+nums[0]);
        int r = 0+1;
            
        int s = sum[r] - sum[l+1];
            
            
        if(n==1) s = 1;
        return (s > 0);
    }
};