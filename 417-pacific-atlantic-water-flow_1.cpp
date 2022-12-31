class Solution {
 private:
  bool dfs_tl(int y, int x, vector<vector<int> >& heights,
           vector<vector<bool> >& visited) {
    if (visited[y][x] == true) return false;
    if (y == 0 || x == 0) return true;
    bool up = false;
    bool left = false;
    if (y - 1 >= 0 && heights[y][x] >= heights[y - 1][x]) {
      up = dfs_tl(y - 1, x, heights, visited);
    }
    if (x - 1 >= 0 && heights[y][x] >= heights[y][x - 1]) {
      left = dfs_tl(y, x - 1, heights, visited);
    }
    visited[y][x] = true;
    return up || left;
  }

  bool dfs_br(int y, int x, vector<vector<int> >& heights,
           vector<vector<bool> >& visited) {
    if (visited[y][x] == true) return false;
    if (y == heights.size() - 1 || x == heights[0].size() - 1) {
      return true;
    }
    bool down = false;
    bool right = false;
    if (y + 1 < heights.size() && heights[y][x] >= heights[y + 1][x]) {
      down = dfs_br(y + 1, x, heights, visited);
    }
    if (x + 1 < heights[0].size() && heights[y][x] >= heights[y][x + 1]) {
      right = dfs_br(y, x + 1, heights, visited);
    }
    visited[y][x] = true;
    return down || right;
  }

 public:
  vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
    vector<vector<int> > results;
    
    for (int i = 0; i < heights.size(); i++) {
      for (int j = 0; j < heights[0].size(); j++) {
        vector<vector<bool> > visited_tl(
          heights.size(), vector<bool>(heights[0].size(), false));
        vector<vector<bool> > visited_br(
          heights.size(), vector<bool>(heights[0].size(), false));
        if (dfs_tl(i, j, heights, visited_tl)
            && dfs_br(i, j, heights, visited_br)) {
          results.push_back({i, j});
        }
      }
    }
    return results;
  }
};

/**
 * Idea: DFS to explore if it is possible to flow to nearby
 * cells. Might need to use two separate DFS functions?
 * For top-left and bottom-right directions.
 */

/* wrong answer */

