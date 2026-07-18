class Solution {
public:

    bool isSafe(vector<string> &board, int row, int col, int n) {
        int duprow = row;
        int dupcol = col;
        
        //left row
        while(col >= 0) {
            if(board[row][col] == 'Q')
                return false;
            col--;
        }
        col = dupcol;

        //upper diagonal
        while(row >= 0 && col >= 0) {
            if(board[row][col] == 'Q')
                return false;
            row--;
            col--;
        }
        col = dupcol;
        row = duprow;

        //lower diagonal
        while(row < n && col >= 0) {
            if(board[row][col] == 'Q')
                return false;
            row++;
            col--;
        }
        return true;
    }   

    void solve(vector<string> &board, int col, vector<vector<string>> &ans, int n){
        if(col == n){
            ans.push_back(board);
            return;
        }

        for(int row = 0; row < n; row++) {
            if(isSafe(board, row, col, n)){
                board[row][col] = 'Q';
                solve(board, col+1, ans, n);
                board[row][col] = '.';
            }
        }
        return;
    }

    vector<vector<string>> solveNQueens(int n) {
        string s(n,'.');
        vector<string> board(n);
        for(int i =0; i<n;i++){
            board[i] = s;
        }

        vector<vector<string>> ans;
        int col =0;
        solve(board,col, ans,n);
        return ans;
    }
};