int dx[] = {0, 0, -1, 1};
int dy[] = {-1, 1, 0, 0};
int n, m, len;


bool solve ( int i,  int j, int k, vector<vector<char>> &ch, string &s )
{
    if ( k >= len ) return 1;
    if ( i >= n || j >= m ) return 0;
    if ( s[k] != ch[i][j] ) return 0; 
    
    int ret = 0;
    
    
    char temp = ch[i][j];
    ch[i][j] = '.';
    for ( int l = 0; l < 4; l++ ) {
        int x = dx[l] + i;
        int y = dy[l] + j;

        if ( x >= 0 && x < n && y >= 0 && y < m && solve ( x, y, k+1, ch, s ) ) ret = 1;
    }
    
    ch[i][j] = temp;
    
    return  ret;
    
}

class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        
        len = word.size();
        n = board.size();
        m = board[0].size();
        
        if (n == 1 && m == 1 && len == 1 && word[0] == board[0][0]) return 1;
        
        for ( int i = 0; i < n; i++ ) {
            for ( int j = 0; j < m; j++ ) {
                if ( solve(i, j, 0, board, word) ) return 1;
            }
        }
        
        return 0;
    }
};








