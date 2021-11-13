class Solution:
    def dailyTemperatures(self, tem: List[int]) -> List[int]:
        n = len(tem)
        id = [0]*101
        lim = 1000000
        ans = [lim]*n
        st = []
        
        for i in reversed(range( 0, n )) :
            
            while ( len(st) ) :
                if ( st[-1] <= tem[i] ):
                    st.pop()
                else:
                    ans[i] = min ( ans[i], id[st[-1]] - i )
                    break
            
            
            st.append ( tem[i] )
            id[tem[i]] = i
            if ( ans[i] == lim ):
                ans[i] = 0
        
        
        return ans