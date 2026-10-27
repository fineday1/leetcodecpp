// we iterate over the entire matrix checking for 'O', for every 'O' that is on the border of the matrix
// we call capture to capture all its neighbours that are also 'O' and mark them as 'T'
// we perform a depth-first search as long as we are within bounds to find all of the neighbours
// lastly we iterate of the entire matrix to transform any remaining 'O' (uncaptured/surrounded) to 'X'
// and any 'T' (capture/unsurrounded) back to 'O'

class Solution {
public:
    void capture(vector<vector<char>>& board, int r, int c) {
        if (r < 0 || c < 0 || r == board.size() || c == board[0].size() || board[r][c] != 'O') return;
        board[r][c] = 'T';
        capture(board, r + 1, c);
        capture(board, r - 1, c);
        capture(board, r, c + 1);
        capture(board, r, c - 1);
    }

    void solve(vector<vector<char>>& board) {
        for (int r = 0; r < board.size(); r++) {
            for (int c = 0; c < board[0].size(); c++) {
                if (board[r][c] == 'O' && ((r == 0 || r == (board.size() - 1)) ||
                                           (c == 0 || c == (board[0].size() - 1)))) 
                capture(board, r, c);
            }
        }

        for (int r = 0; r < board.size(); r++) {
            for (int c = 0; c < board[0].size(); c++) {
                if (board[r][c] == 'O') board[r][c] = 'X';
                if (board[r][c] == 'T') board[r][c] = 'O';
            }
        }
    }
};
