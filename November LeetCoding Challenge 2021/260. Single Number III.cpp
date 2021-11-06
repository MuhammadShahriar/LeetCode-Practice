class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        unordered_map<int, int> cnt;
        for ( auto u : nums ) cnt[u]++;
        vector<int> ans;
        for ( auto u : nums ) if ( cnt[u] == 1 ) ans.push_back(u);
        return ans;
    }
};