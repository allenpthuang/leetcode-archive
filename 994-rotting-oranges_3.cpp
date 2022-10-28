class Solution {
 public:
  int orangesRotting(vector<vector<int>>& grid) {
    // BFS. Push the rotten ones into a deque, and going thru
    // one layer counts as one second. When processing a
    // rotten, go to its four-way's, makr and append to the deque.
    
    deque<vector<int> > rotten;
    int orig_rotten = 0;
    int orig_fresh = 0;
    for (int i = 0; i < grid.size(); i++) {
      for (int j = 0; j < grid[0].size(); j++) {
        if (grid[i][j] == 2) {
          rotten.push_back(vector<int>{i, j}); // {row, col}
          orig_rotten++;
        }
        if (grid[i][j] == 1) {
          orig_fresh++;
        }
      }
    }
    if (orig_fresh == 0) {
      return 0;
    } 
    
    int total_rotten = 0;
    int rounds = 0;
    int rot_row = -1;
    int rot_col = -1;
    while (! rotten.empty()) {
      int n_rotten = rotten.size();
      total_rotten += n_rotten;
      for (int i = 0; i < n_rotten; i++) {
        rot_row = rotten.front()[0];
        rot_col = rotten.front()[1];
        rotten.pop_front();
        if (rot_row - 1 >= 0 && grid[rot_row - 1][rot_col] == 1) {
          rotten.push_back(vector<int>{rot_row - 1, rot_col});
          grid[rot_row - 1][rot_col] = 2;
        }
        if (rot_col - 1 >= 0 && grid[rot_row][rot_col - 1] == 1) {
          rotten.push_back(vector<int>{rot_row, rot_col - 1});
          grid[rot_row][rot_col - 1] = 2;
        }
        if (rot_row + 1 < grid.size() && grid[rot_row + 1][rot_col] == 1) {
          rotten.push_back(vector<int>{rot_row + 1, rot_col});
          grid[rot_row + 1][rot_col] = 2;
        }
        if (rot_col + 1 < grid[0].size() && grid[rot_row][rot_col + 1] == 1) {
          rotten.push_back(vector<int>{rot_row, rot_col + 1});
          grid[rot_row][rot_col + 1] = 2;
        }
      }
      rounds++;
    }
    if (total_rotten == orig_rotten + orig_fresh) {
      return rounds - 1;
    } else {
      return -1;
    }
  }
};

/* Runtime: 2 ms, faster than 98.15% of C++ online submissions for Rotting Oranges.
 * Memory Usage: 13.5 MB, less than 16.79% of C++ online submissions for Rotting Oranges.
 */

