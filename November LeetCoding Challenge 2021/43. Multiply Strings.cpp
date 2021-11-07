class Solution {
public:
    string multiply(string num1, string num2) {
        reverse ( num1.begin(), num1.end() );
        reverse ( num2.begin(), num2.end() );
        
        if ( num1 == "0" || num2 == "0" ) return "0";
        
        int n = num1.size();
        int m = num2.size();
        
        
        vector<int> res(2*n*m);
        vector<string> ans;
        if ( num1.size() < num2.size() ) swap( num1, num2 );
        for ( int i = 0; i < num2.size(); i++ ) {
            string val;
            int hand = 0;
            
            
            for ( int j = 0; j < num1.size(); j++ ) {
                int mul = ( num1[j] - '0' ) * ( num2[i] - '0' );
                mul += hand;
                res[i+j] += ( ( mul % 10 ) );
                hand = mul / 10;
            }
            
            int id = i+num1.size();
            if (hand != 0) {
                
                while ( hand > 0 ) {
                    res[id++] += (hand % 10);
                    
                    hand /= 10;
                }
            }
            
        }
        
        string ret;
        for ( int i = 0; i < res.size()-1; i++ ) {
            if ( res[i] > 9 ) {
                res[i+1] += res[i] / 10;
                res[i] %= 10;
            }
        } 
        for ( auto u : res ) ret += u+'0';
        while ( ret.back() == '0' ) ret.pop_back();
        reverse ( ret.begin(), ret.end() );
        return ret;
    }
};