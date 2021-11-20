class Solution:
    def singleNonDuplicate(self, nums: List[int]) -> int:
        n = len ( nums )
        l = 0
        r = n-1
        
        while ( l < r ) :
            mid = ( l + r ) >> 1
            id1 = -1
            
            if ( mid-1 >= 0 and nums[mid-1] == nums[mid]) :
                id1 = mid-1
                
            elif ( mid+1 < n and nums[mid+1] == nums[mid] ) :
                id1 = mid
                
            else:
                return nums[mid]
            
            if ( id1 % 2  == 1 ) :
                r = mid-1
            else :
                l = mid+1
                
        return nums[l]
        