class CombinationIterator {
public:
    vector<string> v;
    CombinationIterator(string s, int len) {
        v.clear();
        int l = s.size();
        
        for ( int mask = 1; mask < ( 1<<l ); mask++ ) {
            string ret;
            int cnt = 0;
            for ( int i = 0; i < l; i++ ) {
                if ( ( 1 << i ) & mask ) {
                    ret += s[i];
                    cnt++;
                }
            }
            
            if ( cnt == len ) {
                v.push_back ( ret );
            }
        }
        
        sort ( v.begin(), v.end() );
        reverse ( v.begin(), v.end() );
    }
    
    string next() {
        string ret = v.back();
        v.pop_back();
        return ret;
    }
    
    bool hasNext() {
        return !v.empty();   
    }
};

/**
 * Your CombinationIterator object will be instantiated and called as such:
 * CombinationIterator* obj = new CombinationIterator(characters, combinationLength);
 * string param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */