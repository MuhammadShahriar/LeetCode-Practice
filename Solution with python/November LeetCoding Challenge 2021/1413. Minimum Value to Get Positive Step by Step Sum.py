class Solution(object):
    def minStartValue(self, nums):
        
        l = 1
        r = 10000+123
        ans = 10000+123
        while ( l <= r ) :
            mid = ( l + r ) >> 1
            tmp = mid
            done = 1
            
            for u in nums :
                tmp += u
                if tmp < 1 :
                    done = 0
                    break
                    
                    
            if done == 1 :
                ans = min ( ans, mid )
                r = mid-1
                
            else :
                l = mid+1
                
        return ans;
        