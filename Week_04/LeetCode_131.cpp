class Solution {
public:
    void solve(vector<vector<char>>& board) {
        if (board.empty() || board[0].empty()) 
            return;

        int rows = board.size();
        int cols = board[0].size();
        for (int i = 0; i < cols; i++) {
            if (board[0][i] == 'O') 
                fill_border(board, 0, i);
            if (board[rows - 1][i] == 'O') 
                fill_border(board, rows - 1, i);
        }
        for (int i = 0; i < rows; i++) {
            if (board[i][0] == 'O') 
                fill_border(board, i, 0);
            if (board[i][cols - 1] == 'O') 
                fill_border(board, i, cols - 1);
        }
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (board[i][j] == 'O') 
                    board[i][j] = 'X';
                if (board[i][j] == '$') 
                    board[i][j] = 'O';
            }
        }
    }
public:
    void fill_border(vector<vector<char>>& board, int row, int col) {
        board[row][col] = '$';
        if (row - 1 >= 0 && board[row - 1][col] == 'O') 
            fill_border(board, row - 1, col);
        if (row + 1 < board.size() && board[row + 1][col] == 'O') 
            fill_border(board, row + 1, col);
        if (col - 1 >= 0 && board[row][col - 1] == 'O') 
            fill_border(board, row, col - 1);
        if (col + 1 < board[0].size() && board[row][col + 1] == 'O') 
            fill_border(board, row, col + 1);
    }
};