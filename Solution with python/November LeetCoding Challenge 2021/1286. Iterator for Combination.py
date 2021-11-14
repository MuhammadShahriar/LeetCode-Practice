v = []
class CombinationIterator
    
    def __init__(self, s str, lent int)
        v.clear()
        l = len(s)
        
        for mask in range ( 1, 1  l ) 
            ret = 
            cnt = 0
            
            for i in range ( 0, l ) 
                if ( ( 1  i ) & mask ) 
                    ret += s[i]
                    cnt = cnt + 1
                    
            if ( cnt == lent ) 
                v.append ( ret )
                
        
        v.sort()
        v.reverse()
        

    def next(self) - str
        ret = v[-1]
        v.pop()
        return ret

    def hasNext(self) - bool
        return ( len(v)  0 )


# Your CombinationIterator object will be instantiated and called as such
# obj = CombinationIterator(characters, combinationLength)
# param_1 = obj.next()
# param_2 = obj.hasNext()