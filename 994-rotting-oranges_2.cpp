class Solution {
 public:
  int orangesRotting(vector<vector<int>>& grid) {
    vector<vector<int> > fresh;
    vector<vector<int> > rotten;
    for (int i = 0; i < grid.size(); i++) {
      for (int j = 0; j < grid[0].size(); j++) {
        if (grid[i][j] == 1) {
          fresh.push_back(vector<int>{i, j});
        } else if (grid[i][j] == 2) {
          rotten.push_back(vector<int>{i, j});
        }
      }
    }
    
    if (fresh.size() > 0 && rotten.size() == 0) {
      return -1;
    } else if (fresh.size() == 0) {
      return 0;
    }
    
    int cnt = -1;
    int n_r = rotten.size();
    do {
      n_r = rotten.size();
      for (int k = 0; k < n_r; k++) {
        int i = rotten[k][0];
        int j = rotten[k][1];
        vector<vector<int> > tmp{
          vector<int>{i+1, j},
          vector<int>{i-1, j},
          vector<int>{i, j+1},
          vector<int>{i, j-1}
        };
        for (const auto& t : tmp) {
          auto it = find(fresh.begin(), fresh.end(), t);
          if (it != fresh.end()) {
            rotten.push_back(vector<int>{t[0], t[1]});
            fresh.erase(it);
          }
        }
      }
      cnt++;
    } while (rotten.size() != n_r);

    if (fresh.size() > 0) {
      return -1;
    } else {
      return cnt;
    }
  }
};

/* Runtime: 71 ms, faster than 5.25% of C++ online submissions for Rotting Oranges.
 * Memory Usage: 24.2 MB, less than 5.23% of C++ online submissions for Rotting Oranges.
 */

