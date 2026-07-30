    class Solution {
    private:
        bool isSafe(int row , int col , int n , vector<string>& board ){
            int drow = row , dcol = col;
            //UD
            while(row>=0 && col>=0){
                if(board[row][col] == 'Q')
                    return false;
                row-- , col--;
            }
            //R
            row = drow , col = dcol;
            while(col>=0){
                if(board[row][col] == 'Q')
                    return false;
                col--;
            }
            //LD
            col = dcol;
            while(row < n && col >= 0){
                if(board[row][col] == 'Q')
                    return false;
                row++ , col--;
            }
            return true;
        }
        void solve(int col , vector<string>& board , vector<vector<string>>& ans , int n){
            if(col == n){
                ans.push_back(board);
                return;
            }
            for(int row = 0 ;row<n;row++){
                if(isSafe(row,col,n,board)){
                    board[row][col] = 'Q';
                    solve(col+1,board,ans,n);
                    board[row][col] = '.';

                }
            }
        }
    public:
        vector<vector<string>> solveNQueens(int n) {
            string s(n,'.');
            vector<string> board(n);
            vector<vector<string>> ans;

            for(int i = 0;i<n;i++){
                board[i] = s;
            }
            solve(0,board,ans,n);
            return ans;
        }
    };