class Solution {
private:
    bool isValid(vector<vector<char>>& board, int row, int col, char c){
    for(int i = 0; i < 9; i++){
        if(board[row][i] == c) return false;           // same row
        if(board[i][col] == c) return false;           // same column
        if(board[3*(row/3) + i/3][3*(col/3) + i%3] == c) return false;  // same 3x3 box
    }
    return true;
}
    bool solve(vector<vector<char>>& board){
        for(int row = 0; row < 9; row++){
            for(int col = 0; col < 9; col++){
                if(board[row][col] == '.'){
                    for(char c = '1'; c <= '9'; c++){
                        if(isValid(board, row, col, c)){
                            board[row][col] = c;
                            if(solve(board)) return true;   // agla empty cell try karo
                            board[row][col] = '.';          // backtrack
                        }
                    }
                    return false;  // koi digit 1-9 fit nahi hui — ye path dead end hai
                }
            }
        }
        return true;  // saare cells filled, no more '.' mila — solved!
    }

public:
    void solveSudoku(vector<vector<char>>& board) {
        solve(board);
    }
};