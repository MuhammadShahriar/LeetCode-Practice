class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        vector<int> cnt(nums.size()+1);
        
        for (auto u : nums) cnt[u]++;
        int l = 0, c = 0;
        for ( int i = 0; i < nums.size(); i++ ) {
            if ( cnt[nums[i]] == 2 ) {
                nums[l++] = nums[i];
                cnt[nums[i]]--;
                c++;
            }
        }
        
        while ( nums.size() > c ) nums.pop_back();
        
        return nums;
    }
};