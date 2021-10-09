
struct vertex {
    int next[26], leaf = 0;
    vertex() {
        fill ( begin(next), end(next), -1 );
    }
};
vector<vertex> trie;

void init () {
    trie.clear();
    trie.emplace_back();
}

int add ( char u, int v )
{
    int c = u - 'a';
        
    if ( trie[v].next[c] == -1 ) {
        trie[v].next[c] = trie.size();
        trie.emplace_back();
    }
        
    return v = trie[v].next[c];
}

bool search ( string s )
{
    int v = 0;
    
    for ( auto u : s ) {
        int c = u - 'a';
        
        if ( trie[v].next[c] == -1 ) {
            return 0;
        }
        
        v = trie[v].next[c];
    }
    
    return 1;
}

int dx[] = {0, 0, -1, 1};
int dy[] = {-1, 1, 0, 0};

void dfs ( int i, int j, int l, vector<vector<char>> &ch, int v )
{
    if (l >= 10) return;
    int n = ch.size();
    int m = ch[0].size();
    
    v = add ( ch[i][j], v );
    
    char temp = ch[i][j];
    ch[i][j] = '.';
    
    for ( int k = 0; k < 4; k++ ) {
        int x = dx[k] + i;
        int y = dy[k] + j;
        
        if ( x >= 0 && x < n && y >= 0 && y < m && ch[x][y] != '.' ) {
            dfs ( x, y, l+1, ch, v );
        }
    }
    
    ch[i][j] = temp;
}

class Solution {
public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        int n = board.size();
        int m = board[0].size();
        
        init();
        
        for ( int i = 0; i < n; i++ ) {
            for ( int j = 0; j < m; j++ ) {
                dfs ( i, j, 0, board, 0 );
            }
        }
        
        vector<string> ans;
        
        for ( auto u : words ) {
            if ( search(u) ) ans.push_back(u);
        }
        
        return ans;
    
    }
};





