int drow[] = {-1, 0, 1, 0};
int dcol[] = {0, 1, 0, -1};
class Solution {
public:
    
    void dfs(int r, int c, vector<vector<char>>& board, vector<vector<int>>& vis) {
        int m = board.size();
        int n = board[0].size();
        vis[r][c] = 1;

        for(int i =0; i<4; i++) {
            int nr = r + drow[i];
            int nc = c + dcol[i];

            if(nr >= 0 && nr < m && nc >= 0 && nc <n && board[nr][nc] == 'O' &&!vis[nr][nc]) {
                dfs(nr, nc, board, vis);
            }
        }
        return;

    }

    void solve(vector<vector<char>>& board) {
        int m = board.size();
        int n = board[0].size();
        vector<vector<int>> vis(m, vector<int>(n, 0));

        for(int i=0; i<n; i++) {

            if(!vis[0][i] && board[0][i] == 'O'){
                dfs(0, i,board,vis);
            }
            if(!vis[m-1][i] && board[m-1][i] == 'O'){
                dfs(m-1,i,board,vis);
            }
        }

        for(int i =0; i<m; i++) {
            if(!vis[i][0] && board[i][0] == 'O'){
                dfs(i,0,board,vis);
            }
            if(!vis[i][n-1] && board[i][n-1] == 'O'){
                dfs(i,n-1, board, vis);
            }
        }

        for(int i =0; i<m; i++){
            for(int j =0; j<n; j++) {

                if(board[i][j] == 'O' && (vis[i][j] == 0)){
                    board[i][j] = 'X';
                }
            }
        }
        return;
    }
};