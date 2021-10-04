int dx[] = {0, 0, -1, 1};
int dy[] ={-1, 1, 0, 0};

class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int ans = 0;
        
        
        for ( int i = 0; i < n; i++ ) {
            for ( int j = 0; j < m; j++ ) {
                
                if ( grid[i][j] == 1 ) {
                    //grid[i][j] = 0;
                    
                    for ( int k = 0; k < 4; k++ ) {
                        int x = i + dx[k];
                        int y = j + dy[k];
                        
                        if ( x >= 0 && y >= 0 && x < n && y < m ) {
                            if ( grid[x][y] == 0 ) ans++;
                        }
                        else ans++;
                    }
                }
            }
        }
        
        
        
        return ans;
    }
};