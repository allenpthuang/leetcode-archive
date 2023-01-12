class Solution {
 private:
  unsigned int m;
  unsigned int n;
  void dfs(vector<vector<char> >& grid, int row, int col) {
    // base case: out-of-bound or stepping into water
    if (row < 0 || row >= m || col < 0 || col >= n
        || grid[row][col] == '0') return;
    
    // sink the current land
    grid[row][col] = '0';
    
    // explore neighboring squares (lands/waters)
    dfs(grid, row + 1, col);
    dfs(grid, row - 1, col);
    dfs(grid, row, col + 1);
    dfs(grid, row, col - 1);
  }

 public:
  int numIslands(vector<vector<char>>& grid) {
    m = grid.size();
    n = grid[0].size();
    int count = 0;

    for (auto row = 0u; row < m; row++) {
      for (auto col = 0u; col < n; col++) {
        // visit if the current square is a land
        if (grid[row][col] == '1') {
          count++; // new island
          dfs(grid, row, col); // visit every neighbors
        }
      }
    }

    return count;
  }
};

/**
 * Idea: Use DFS or BFS to explore connected lands, and
 * make them into waters ('0') so that we won't visit any
 * of them again. Increase the count of islands when we
 * finish one search (connected lands exhausted).
 */

/* Runtime
31 ms
Beats
98.13%
Memory
12.3 MB
Beats
87.13%
*/

