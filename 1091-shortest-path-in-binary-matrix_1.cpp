class Solution {
 private:
  
 public:
  int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
    // the start is the top-left
    // the end is the bottom-right
    // the grid is n by n
    int n = grid.size();
    pair<int, int> start{0, 0};
    pair<int, int> end{n - 1, n - 1};
    
    /*
    int result = -1;
    vector<vector<int> > dp(n, vector<int>(n, 0));
    if (grid[0][0] == 0) {
      dp[0][0]
    }
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        dp[]
      }
    */
    
    int result = 0; 
    // use a deque to perform BFS
    deque<pair<int, int> > dq;
    if (grid[start.first][start.second] == 0) {
      dq.push_back(start);
    } else {
      return -1;
    }
    if (grid[end.first][end.second] == 1) {
      return -1;
    }
    while (! dq.empty()) {
      result++;
      int n_q = dq.size();
      pair<int, int> p;
      for (int k = 0; k < n_q; k++) {
        p = dq.front();
        dq.pop_front();
        if (p == end) {
          return result;
        }
        if (grid[p.first][p.second] == 0) {
          grid[p.first][p.second] = 1;
          for (int i = -1; i <= 1; i++) {
            for (int j = -1; j <= 1; j++) {
              if (! (i == 0 && j == 0)) {
                if (p.first + i >= 0 && p.first + i < n
                    && p.second + j >= 0 && p.second + j < n
                    && grid[p.first + i][p.second + j] == 0) {
                  dq.push_back(pair<int, int>{p.first + i, p.second + j});
                }
              }
            }
          }
        }
      }
    }
    
    return -1;
  }
};

/* Runtime: 83 ms, faster than 79.02% of C++ online submissions for Shortest Path in Binary Matrix.
 * Memory Usage: 22.7 MB, less than 39.75% of C++ online submissions for Shortest Path in Binary Matrix.
 */

