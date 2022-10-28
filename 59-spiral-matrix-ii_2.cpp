class Solution {
 public:
  vector<vector<int>> generateMatrix(int n) {
    vector<vector<int> > m(n, vector<int> (n, 0));

    int col = 0;
    int row = 0;
    // i-th "layer"
    int counter = 1;
    
    for (int i = 0; i < n - 1; i++) {
      col = i;
      row = i;
      for (; col < n - i - 1; col++) {
        m[row][col] = counter;
        counter++;
      }

      for (; row < n - i - 1; row++) {
        m[row][col] = counter;
        counter++;
      }

      for (; col > i; col--) {
        m[row][col] = counter;
        counter++;
      }

      for (; row > i; row--) {
        m[row][col] = counter;
        counter++;
      }
    }
    
    if (n % 2 != 0) {
      m[n/2][n/2] = counter;
    }
    
    return m;
  }
};

/* Runtime: 0 ms, faster than 100.00% of C++ online submissions for Spiral Matrix II.
 * Memory Usage: 6.4 MB, less than 85.84% of C++ online submissions for Spiral Matrix II.
 */

