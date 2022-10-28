class Solution {
 private:
  const int START_DIGIT = 1;
  const int END_DIGIT = 9;
  void backtracking(vector<vector<int> >& result, vector<int>& cur_res,
                    int k, int n, int cur_num, int cur_sum) {
    if (k == 0) {
      if (cur_sum == n) {
        result.push_back(cur_res);
      }
      return;
    }
    if (cur_sum > n) {
      return;
    }
    for (int i = cur_num; i <= END_DIGIT; i++) {
      cur_res.push_back(i);
      backtracking(result, cur_res, k - 1, n, i + 1, cur_sum + i);
      cur_res.pop_back();
    }
  }

 public:
  vector<vector<int>> combinationSum3(int k, int n) {
    vector<vector<int> > result;
    vector<int> cur_res;
    backtracking(result, cur_res, k, n, START_DIGIT, 0);
    return result;
  }
};

/* Runtime: 2 ms, faster than 56.13% of C++ online submissions for Combination Sum III.
 * Memory Usage: 6.5 MB, less than 68.28% of C++ online submissions for Combination Sum III.
 */

