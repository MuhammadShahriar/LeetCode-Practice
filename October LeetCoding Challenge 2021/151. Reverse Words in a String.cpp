class Solution {
public:
    string reverseWords(string s) {
        
        string ans;
        vector<string> v;
        string c;
        
        for ( auto u : s ) {
            if ( isspace(u) ) {
                if ( !c.empty() ) {
                    v.push_back(c);
                    c.clear();
                }
            }
            else c += u;
        }
        
        if ( !c.empty() ) {
            v.push_back(c);
        }
        
        reverse ( v.begin(), v.end() );
        
        for (auto u : v) {
            if ( !ans.empty() ) ans += " ";
            ans += u;
        }
        
        return ans;
    }
};