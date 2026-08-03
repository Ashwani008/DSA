class Solution {
public:

    void bfs(int r, int c, vector<vector<char>> &grid, vector<vector<int>> &vis, int m, int n) {
        queue<pair<int, int>> q;
        q.push({r,c});
        int drow[] ={-1, 0, 1, 0};
        int dcol[] = {0, 1, 0, -1};

        while(!q.empty()) {
            auto v = q.front();
            int row = v.first;
            int col = v.second;
            vis[row][col] = 1;
            q.pop();

            for(int i =0; i<4; i++){
                int nr = row + drow[i];
                int nc = col + dcol[i];

                if(nr >= 0 && nr <m && nc >= 0 && nc < n && !vis[nr][nc] && grid[nr][nc] == '1') {
                    vis[nr][nc] = 1;
                    q.push({nr, nc});
                }
            } 
        }
        return;
    }

    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> vis(m, vector<int>(n,0));
        int cnt = 0;

        for(int i =0; i<m; i++) {
            for(int j =0; j<n; j++) {
                if (!vis[i][j] && grid[i][j] == '1') {
                    bfs(i,j,grid,vis,m,n);
                    cnt++;
                }

            }
        }
        return cnt;

    }
};