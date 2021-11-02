
    int dx[] = {0, 0, -1, 1};
    int dy[] = {-1, 1, 0, 0};

class Solution {
public:
    int f1 = 0, n, m, com = 0;
    int vis[213][213];
    int cnt[5000];
    
    void dfs ( int x, int y, vector<vector<char>>& b )
    {
        if ( x == 0 || x == n-1 || y == 0 || y == m-1 ) f1 = 1;
        vis[x][y] = com;
        
        for ( int i = 0; i < 4; i++ ) {
            int x1 = dx[i] + x;
            int y1 = dy[i] + y;
            
            if ( x1 >= 0 && x1 < n && y1 >= 0 && y1 < m && b[x1][y1] == 'O' && vis[x1][y1] == 0 ) {
                dfs ( x1, y1, b );
            }
        }
        
    }
    
    
    void solve(vector<vector<char>>& b) {
        n = b.size();
        m = b[0].size();
        for ( int i = 0; i < n; i++ ) {
            for ( int j = 0; j < m; j++ ) vis[i][j] = 0;
        }
        
        com = 0;
        for ( int i = 0; i < n; i++ ) {
            for ( int j = 0; j < m; j++ ) {
                if ( vis[i][j] == 0 && b[i][j] == 'O' ) {
                    com++;
                    cnt[com] = 0;
                    f1 = 0;
                    
                    dfs ( i, j, b );
                    if ( !f1 ) cnt[com] = 1;
                }
            }
        }
        
        
        for ( int i = 0; i < n; i++ ) {
            for ( int j = 0; j < m; j++ ) {
                ///cout << i << " " << j << " " << vis[i][j] << " " << cnt[vis[i][j]] << endl;
                if ( cnt[vis[i][j]] ) b[i][j] = 'X';  
            }
        }
    }
};