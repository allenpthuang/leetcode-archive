class Solution {
 private:
  void dfs(vector<vector<char> >& grid, int row, int col) {
    grid[row][col] = '0';
    for (int i = row - 1; i <= row + 1; i++) {
      if (i < 0 || i >= grid.size() || grid[i][col] == '0') {
        continue;
      } else {
        dfs(grid, i, col);
      }
    }
    for (int j = col - 1; j <= col + 1; j++) {
      if (j < 0 || j >= grid[0].size() || grid[row][j] == '0') {
        continue;
      } else {
        dfs(grid, row, j);
      }
    }
  }
 public:
  int numIslands(vector<vector<char>>& grid) {
    int count = 0;
    for (int i = 0; i < grid.size(); i++) {
      for (int j = 0; j < grid[0].size(); j++) {
        if (grid[i][j] == '1') {
          count++;
          dfs(grid, i, j);
        }
      }
    }
    return count;
  }
};

/* Runtime: 37 ms, faster than 91.90% of C++ online submissions for Number of Islands.
 * Memory Usage: 12.3 MB, less than 82.28% of C++ online submissions for Number of Islands.
 */

