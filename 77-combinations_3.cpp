class Solution {
 private:
  void worker(vector<vector<int> >& result, int cur_num, int n, int k,
              vector<int>& cur_res) {
    if (k == 0) {
      result.push_back(cur_res);
      return;
    }
    
    for (int i = cur_num; i <= n; i++) {
      cur_res.push_back(i);
      worker(result, i + 1, n, k - 1, cur_res);
      cur_res.pop_back();
    }
    
  }
 public:
  vector<vector<int>> combine(int n, int k) {
    vector<vector<int> > result;
    vector<int> cur_res;
    worker(result, 1, n, k, cur_res);
 
    return result;
  }
};

/* Runtime: 28 ms, faster than 76.12% of C++ online submissions for Combinations.
 * Memory Usage: 9.1 MB, less than 81.09% of C++ online submissions for Combinations.
 */

