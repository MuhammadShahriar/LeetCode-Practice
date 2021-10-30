typedef long long ll;

ll MOD = 1e9+7;

inline void normal(ll &a) { a %= MOD; (a < 0) && (a += MOD); }
inline ll modMul(ll a, ll b) { a %= MOD, b %= MOD; normal(a), normal(b); return (a*b)%MOD; }
inline ll modAdd(ll a, ll b) { a %= MOD, b %= MOD; normal(a), normal(b); return (a+b)%MOD; }
inline ll modSub(ll a, ll b) { a %= MOD, b %= MOD; normal(a), normal(b); a -= b; normal(a); return a; }
inline ll modPow(ll b, ll p) { ll r = 1; while(p) { if(p&1) r = modMul(r, b); b = modMul(b, b); p >>= 1; } return r; }
inline ll modInverse(ll a) { return modPow(a, MOD-2); }
inline ll modDiv(ll a, ll b) { return modMul(a, modInverse(b)); }

int p1 = 29, p2 = 31;

class Solution {
public:
    string longestDupSubstring(string s) {
        int n = s.size();
        
        int l = 1, r = n, ans = 0, id = n;
        
        while ( l <= r ) {
            ll pw1 = 1, pw2 = 1;
            int mid = ( l + r ) >> 1;
            
            unordered_map<ll, bool> vis1, vis2;
            ll Hash1 = 0, Hash2 = 0;
            
            for ( int i = n-mid; i < n; i++ ) {
                MOD = 1e9+7;
                Hash1 = modAdd ( Hash1, modMul ( pw1, (s[i] - 'a')+1 ) );
                if ( i != n-1 ) pw1 = modMul (pw1, p1);
                
                MOD = 1e9+9;
                Hash2 = modAdd ( Hash2, modMul ( pw2, (s[i] - 'a')+1 ) );
                if ( i != n-1 ) pw2 = modMul (pw2, p2);
            }
            
            
            
            vis1[Hash1] = 1;
            vis2[Hash2] = 1;
            bool done = 0;
            int c = -1;
            int st = n-mid-1, en = n-2;
            
            while (st >= 0) {
                MOD = 1e9+7;
                Hash1 = modSub ( Hash1, modMul ( (s[en+1]-'a')+1, pw1 ) );
                Hash1 = ( Hash1 * p1 ) % MOD;
                Hash1 += (s[st]-'a')+1;
                
                
                MOD = 1e9+9;
                Hash2 = modSub ( Hash2, modMul ( (s[en+1]-'a')+1, pw2 ) );
                Hash2 = ( Hash2 * p2 ) % MOD;
                Hash2 += ((s[st]-'a')+1 );
                
                if ( vis1[Hash1] && vis2[Hash2] ) {
                    done = 1;
                    c = st;
                    break;
                }
                
                vis1[Hash1] = vis2[Hash2] = 1;
                st--, en--;
            }
            
            if ( done ) {
                if ( ans < mid  ) {
                    id = c;
                    ans = mid;
                }
                l = mid+1;
            }
            else r = mid-1;
            
        }
        
        string ret;
        if ( ans == n ) return "";
        for ( int i = id; i < id + ans; i++ ) ret += s[i];
        return ret;
        
    }
};




