class Solution {
 private:
  bool visit(int i, int j, vector<vector<char>>& board,
             string& word, int cur_idx, vector<vector<bool> >& visited) {
    if (board[i][j] != word[cur_idx]) {
      return false;
    } else if (cur_idx == word.size() - 1) {
      return true;
    }
    
    for (int x = i - 1; x <= i + 1; x++) {
      if (x >= 0 && x < board.size() && x != i && visited[x][j] == false) {
        visited[x][j] = true;
        if (visit(x, j, board, word, cur_idx + 1, visited) == true) {
          return true;
        }
        visited[x][j] = false;
      }
    }
    for (int y = j - 1; y <= j + 1; y++) {
      if (y >= 0 && y < board[0].size() && y != j && visited[i][y] == false) {
        visited[i][y] = true;
        if (visit(i, y, board, word, cur_idx + 1, visited) == true) {
          return true;
        }
        visited[i][y] = false;
      }
    }
    return false;
  }

 public:
  bool exist(vector<vector<char>>& board, string word) {
    vector<vector<bool> > visited(board.size(), vector<bool>(board[0].size(), false));
    for (int i = 0; i < board.size(); i++) {
      for (int j = 0; j < board[0].size(); j++) {
        visited[i][j] = true;
        if (visit(i, j, board, word, 0, visited) == true) {
          return true;
        }
        visited[i][j] = false;
        visited = vector<vector<bool> >(board.size(), vector<bool>(board[0].size(), false));
      }
    }
    return false;
  }
};

/* Runtime: 315 ms, faster than 87.80% of C++ online submissions for Word Search.
 * Memory Usage: 8.5 MB, less than 5.95% of C++ online submissions for Word Search.
 */

