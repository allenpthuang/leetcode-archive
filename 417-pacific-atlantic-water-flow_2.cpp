class Solution {
 private:
  void dfs(int row, int col, int prev_height,
           const vector<vector<int> >& heights,
           vector<vector<bool> >& visited) {
    // base case
    if (row < 0 || col < 0 ||
        row >= heights.size() || col >= heights[0].size() ||
        visited[row][col] == true ||
        heights[row][col] < prev_height) {
      return;
    }

    // record visited
    visited[row][col] = true;

    // go to four directions
    dfs(row + 1, col, heights[row][col], heights, visited);
    dfs(row - 1, col, heights[row][col], heights, visited);
    dfs(row, col + 1, heights[row][col], heights, visited);
    dfs(row, col - 1, heights[row][col], heights, visited);
  }

 public:
  vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
    auto m = heights.size();
    auto n = heights[0].size();
    vector<vector<bool> > visited_atlantic(m, vector<bool>(n));
    vector<vector<bool> > visited_pacific(m, vector<bool>(n));
    for (auto row = 0u; row < m; row++) {
      dfs(row, 0, 0, heights, visited_pacific);
      dfs(row, n - 1, 0, heights, visited_atlantic);
    }
    for (auto col = 0u; col < n; col++) {
      dfs(0, col, 0, heights, visited_pacific);
      dfs(m - 1, col, 0, heights, visited_atlantic);
    }

    vector<vector<int> > results;
    for (auto row = 0; row < m; row++) {
      for (auto col = 0; col < n; col++) {
        if (visited_atlantic[row][col] == true &&
            visited_pacific[row][col] == true) {
              results.push_back({row, col});
        }
      }
    }

    return results;
  }
};

/** Idea: oceans flood the land!!
 */

/* Runtime
49 ms
Beats
82.36%
Memory
17.4 MB
Beats
87.81%
*/

