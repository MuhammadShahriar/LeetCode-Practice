int g[25][25];
int n, m, cnt = 0, res;

int dx[] = {0, 0, -1, 1};
int dy[] = {-1, 1, 0, 0};

void dfs( int i, int j, int c )
{
    if ( g[i][j] == 2 ) {
        res += ( c == cnt );
        return;
    }
    g[i][j] = -1;
    
    
    for ( int k = 0; k < 4; k++ ) {
        int x = dx[k] + i;
        int y = dy[k] + j;
        
        if ( x >= 0 && x < n && y >= 0 && y < m && g[x][y] != -1 ) {
            dfs ( x, y, c + 1 );
        }
    }
    g[i][j] = 0;
}

class Solution {
public:
    int uniquePathsIII(vector<vector<int>>& grid) {
        n = grid.size();
        m = grid[0].size();
        cnt = 1;
        res = 0;
        
        int sx, sy;
        for ( int i = 0; i < n; i++ ) {
            for ( int j = 0; j < m; j++ ) {
                g[i][j] = grid[i][j];
                if ( g[i][j] == 1 ) {
                    sx = i;
                    sy = j;
                }
                
                if(g[i][j] == 0) cnt++;
            }
        }
        
        dfs(sx, sy, 0);
        return res;
    }
};