class Solution {
 public:
  int orangesRotting(vector<vector<int>>& grid) {
    vector<vector<int> > fresh;
    vector<vector<int> > rotten;
    for (int i = 0; i < grid.size(); i++) {
      for (int j = 0; j < grid[0].size(); j++) {
        if (grid[i][j] == 1) {
          vector<int> tmp(2, -1);
          tmp[0] = i;
          tmp[1] = j;
          fresh.push_back(tmp);
        } else if (grid[i][j] == 2) {
          vector<int> tmp(2, -1);
          tmp[0] = i;
          tmp[1] = j;
          rotten.push_back(tmp);
        }
      }
    }
    
    if (rotten.size() == 0) {
      return -1;
    } else if (fresh.size() == 0 && rotten.size() > 0) {
      return 0;
    }
    
    int cnt = 0;
    //vector<vector<int> > orig_gird = grid;
    //vector<vector<int> > after_grid = orig_grid;
    int n_r = rotten.size();
    int n_f = fresh.size();
    vector<int> new_rotten;
    do {
      n_r = rotten.size();
      for (const auto& r : rotten) {
        int i = r[0];
        int j = r[1];
        vector<vector<int> > tmp{
          vector<int>{i+1, j},
          vector<int>{i-1, j},
          vector<int>{i, j+1},
          vector<int>{i, j-1}
        };
        for (const auto& t : tmp) {
          auto it = find(fresh.begin(), fresh.end(), t);
          if (it != fresh.end()) {
            new_rotten = vector<int>{t[0], t[1]};
            rotten.push_back(new_rotten);
            fresh.erase(it);
          }
        }
      }
      cnt++;
    } while (rotten.size() != n_r);

    if (fresh.size() > 0) {
      return -1;
    } else {
      return cnt - 1;
    }
  }
};

/* runtime error */

