class Solution {
public:
    bool check(int row, int col, vector<vector<char>>& board, string word,
               int index) {
        int m = board.size();
        int n = board[0].size();
        if (index == word.length()) {

            return true;
        }
        if (row < 0 || col < 0 || row >= m || col >= n ||
            board[row][col] != word[index]) {

            return false;
        }
        char p = board[row][col];
        board[row][col] = '!';
        bool down = check(row + 1, col, board, word, index + 1);
        bool right = check(row, col + 1, board, word, index + 1);
        bool up = check(row - 1, col, board, word, index + 1);
        bool left = check(row, col - 1, board, word, index + 1);
        board[row][col] = p;
        return left || right || up || down;
    }
    bool exist(vector<vector<char>>& board, string word) {
        int m = board.size();
        int n = board[0].size();
        // vector<vector<int>> vis(m, vector<int>(n, 0));
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (board[i][j] == word[0]) {
                    if (check(i, j, board, word, 0))
                        return true;
                }
            }
        }
        return false;
    }
};
