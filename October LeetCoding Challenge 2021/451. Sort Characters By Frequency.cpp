class Solution {
public:
    string frequencySort(string s) {
        map<char, int> cnt;
        
        vector<pair<int, char>> v;
        for ( auto u : s ) {
            cnt[u]++;
        }
        
        for ( char i = 'a'; i <= 'z'; i++ ) v.push_back ( { cnt[i], i} );
        for ( char i = 'A'; i <= 'Z'; i++ ) v.push_back ( { cnt[i], i} );
        for ( char i = '0'; i <= '9'; i++ ) v.push_back ( { cnt[i], i} );
        
        sort (v.rbegin(), v.rend());
        
        string ans;
        for ( auto u : v ) {
            for ( int i = 0; i < u.first; i++ ) ans += u.second;
        }
        
        return ans;
    }
};