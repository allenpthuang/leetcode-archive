class Solution {
 public:
  bool reachingPoints(int sx, int sy, int tx, int ty) {
    int size_x = max(sx, tx);
    int size_y = max(sy, ty);
    vector<vector<bool> > dp(size_x + 1, vector<bool>(size_y + 1, false));
    dp[sx][sy] = true;
    for (int i = sx; i <= tx; i++) {
      for (int j = sy; j <= ty; j++) {
        int prev_x = i - j;
        int prev_y = j - i;
        if (prev_x >= 0 && dp[prev_x][j] == true) {
          dp[i][j] = true;
        }
        if (prev_y >= 0 && dp[i][prev_y] == true) {
          dp[i][j] = true;
        }
      }
    }
    return dp[tx][ty];
  }
};

/* OOM */

