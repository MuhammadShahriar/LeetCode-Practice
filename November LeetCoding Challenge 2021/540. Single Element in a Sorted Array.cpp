class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int ret = 0;
        
        int l = 0, r = nums.size()-1;
        
        while ( l < r ) {
            int mid = ( l + r ) >> 1;
            int id1, id2;
            if ( mid - 1 >= 0 && nums[mid-1] == nums[mid] ) {
                id1 = mid-1;
                id2 = mid;
            }
            else if ( mid + 1 < nums.size() && nums[mid+1] == nums[mid] ) {
                id1 = mid;
                id2 = mid+1;
            }
            else return nums[mid];
            
            if ( id1 % 2 ) r = mid-1;
            else l = mid+1;
        }
        
        return nums[l];
    }
};