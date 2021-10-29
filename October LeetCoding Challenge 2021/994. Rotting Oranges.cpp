class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        
        int dx[] = {0, 0, -1, 1};
        int dy[] = {-1, 1, 0, 0};
        
        bool done = 0;
        int ans = 0;
        int cnt = 0;
        
        while ( !done ) {
            cnt++;
            if ( cnt >= 200 ) return -1;
            done = 1;
            bool no = 1;
            
            
            
            
            for ( int i = 0; i < n; i++ ) {
                for ( int j = 0; j < m; j++ ) {
                    if ( grid[i][j] == 1 ) {
                        done = 0;
                    }
                    if ( grid[i][j] == 2 ) no = 0;
                }
            }
            
            if ( done ) break;
            if ( no  ) return -1;
            ans++;
            
            vector<pair<int,int>> p;
            for ( int i = 0; i < n; i++ ) {
                for ( int j = 0; j < m; j++ ) {
                    if ( grid[i][j] == 2 ) {
                        for ( int k = 0; k < 4; k++ ) {
                            int x = i + dx[k];
                            int y = j + dy[k];
                            
                            if ( x >= 0 && x < n && y >= 0 && y < m && grid[x][y] == 1 ) {
                                p.push_back({x, y});
                            }
                        }
                    }
                }
            }
            
            
            for ( auto u : p ) grid[u.first][u.second] = 2;
        }
        
        return ans;
    }
};