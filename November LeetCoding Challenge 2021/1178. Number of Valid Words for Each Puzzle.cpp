

class Solution {
    public:
    
    int getMask ( string s ) {
        int mask = 0;
        for ( auto u : s ) mask = mask | ( 1 << ( u - 'a' ) );
        return mask;
    }
    
    
    vector<int> findNumOfValidWords(vector<string>& words, vector<string>& puzzles) {
        
        unordered_map<int, int> cnt;
        for ( auto u : words ) cnt[getMask(u)]++;
        
        vector<int> ans;
        for ( auto u : puzzles ) {
            int mask = getMask(u);
            int submask = mask;
            
            int f = u[0] - 'a';
            int cur = 0;
            while ( submask != 0 ) {
                if ( submask & ( 1 << f ) ) cur += ( cnt[submask] );
                
                submask = ( submask - 1 ) & mask;
            }
            
            ans.push_back ( cur );
        }
        
        return ans;
    }
};