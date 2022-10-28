class Solution {
 public:
  int minHeightShelves(vector<vector<int>>& books, int shelfWidth) {
    vector<int> dp(books.size() + 1, INT_MAX);  // dp[k]: min total height at k-th book, k strating from 1
    dp[0] = 0;  // zero-th book requires 0 height
    
    for (int i = 0; i < books.size(); i++) {
      // dp[k] = dp[k - 1] + books[i][1], where k = i + 1
      // assume we put the book at a new level first
      dp[i + 1] = dp[i] + books[i][1];
      
      int cur_width = books[i][0];
      int cur_tallest = books[i][1];
      for (int j = i - 1; j >= 0; j--) {  // go thru previous books
        cur_width += books[j][0];
        cur_tallest = max(cur_tallest, books[j][1]);
        // this works because eventually we are going to use dp[j] at the previous level,
        // and that j-th book would be the one just before the shelf explodes
        if (cur_width <= shelfWidth) {
          dp[i + 1] = min(dp[i + 1], dp[j] + cur_tallest);
        }
      }
    }
    return dp[books.size()];
  }
};

/* Runtime: 26 ms, faster than 11.78% of C++ online submissions for Filling Bookcase Shelves.
 * Memory Usage: 8.1 MB, less than 95.11% of C++ online submissions for Filling Bookcase Shelves.
 */

