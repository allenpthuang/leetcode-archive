class Solution {
 private:
  void worker(vector<vector<vector<bool> > >& result, vector<vector<bool> >& cur_res,
             int n) {
    if (n == 0) {
      result.push_back(cur_res);
      return;
    }
    
    for (int i = 0; i < cur_res[0].size(); i++) {
      if (cur_res[0][i] == true) continue;
      for (int j = 0; j < cur_res[1].size(); j++) {
        if (cur_res[0][i] == false && cur_res[1][j] == false) {
          cur_res[0][i] = true;
          cur_res[1][j] = true;
          worker(result, cur_res, n - 1);
          cur_res[1][j] = false;
          cur_res[0][i] = false;
        }
      }
    }
  }
  
  vector<string> strify(vector<vector<bool> >& bool_res) {
    vector<string> result(bool_res[0].size(), string(bool_res[1].size(), '.'));
    for (int i = 0; i < bool_res[0].size(); i++) {
      for (int j = 0; j < bool_res[1].size(); j++) {
        if (bool_res[0][i] && bool_res[1][j]) {
          result[i][j] = 'Q';
        } else {
          result[i][j] = '.';
        }
      }
    }
    return result;
  }
  
 public:
  vector<vector<string>> solveNQueens(int n) {
    vector<vector<vector<bool> > > result;
    vector<vector<bool> > cur_res(2, vector<bool>(n, false));
    
    worker(result, cur_res, n);
    
    vector<vector<string> > str_result;
    for (auto& bool_res : result) {
      str_result.push_back(strify(bool_res));
    }
    
    return str_result;
  }
};

/* wrong answer */

