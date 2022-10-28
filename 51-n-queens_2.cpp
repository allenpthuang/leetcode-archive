class Solution {
 private:
  bool is_valid(vector<string>& cur_res, int col, int row) {
    for (int i = 0; i < cur_res.size(); i++) {
      if (cur_res[col][i] == 'Q') return false;
      if (cur_res[i][row] == 'Q') return false;
    }
    
    for (int i = col - 1, j = row - 1; i >= 0 && j >= 0; i--, j--) {
      if (cur_res[i][j] == 'Q') return false;
    }

    for (int i = col + 1, j = row - 1; i < cur_res.size() && j >= 0; i++, j--) {
      if (cur_res[i][j] == 'Q') return false;
    }
    
    return true;
  }

  void worker(vector<vector<string> >& result, vector<string>& cur_res,
              int cur_row = 0) {
    if (cur_row == cur_res.size()) {
      result.push_back(cur_res);
      return;
    }
    for (int col = 0; col < cur_res.size(); col++) {
      if (is_valid(cur_res, col, cur_row)) {
        cur_res[col][cur_row] = 'Q';
        worker(result, cur_res, cur_row + 1);
        cur_res[col][cur_row] = '.';
      }
    }
  }

 public:
  vector<vector<string>> solveNQueens(int n) {
    vector<vector<string> > result;
    vector<string> cur_res(n, string(n, '.'));
    worker(result, cur_res);
    return result;
  }
};

/* Runtime: 11 ms, faster than 53.21% of C++ online submissions for N-Queens.
 * Memory Usage: 7.3 MB, less than 71.85% of C++ online submissions for N-Queens.
 */

