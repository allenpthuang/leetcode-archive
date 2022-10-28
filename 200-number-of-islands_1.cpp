class Solution {
 private:
  struct hashFunction {
    size_t operator()(const pair<int, int> &x) const {
      return x.first ^ x.second;
    }
  };

  int find_or_add_to_new_group(pair<int, int> coors,
                               vector<unordered_set<pair<int, int>, hashFunction> >& groups) {
    if (groups.size() == 0) {
      return 0;
    }
    for (int i = 0; i < groups.size(); i++) {
      if (groups[i].count(coors) > 0) {
        return i;
      }
    }
    return groups.size();
  }

 public:
  int numIslands(vector<vector<char>>& grid) {
    int result = 0;
    
    vector<unordered_set<pair<int, int>, hashFunction> > groups;  // the pair: (i, j) = (row, col)
    for (int i = 0; i < grid.size(); i++) {
      for (int j = 0; j < grid[0].size(); j++) {
        if (grid[i][j] == '1') {
          int cur_num_groups = groups.size();
          int cur_grp_idx = find_or_add_to_new_group(pair<int, int>{i, j}, groups);
          if (cur_grp_idx + 1 > cur_num_groups) {  // new group
            
          }
          for (int p = i - 1; p <= i + 1; p++) {
            for (int q = j - 1; q <= j + 1; q++) {
              groups[cur_grp_idx].insert(pair<int, int>{p, q});
            }
          }
        }
      }
    }
    return groups.size();
    
  }
};

/* runtime error */

