class Solution {
 public:
  vector<vector<int>> merge(vector<vector<int>>& intervals) {
    sort(intervals.begin(), intervals.end());
    vector<vector<int> > result;
    int cur_x = intervals[0][0];
    int cur_y = intervals[0][1];
    for (int i = 1; i < intervals.size(); i++) {
      if (intervals[i][0] <= cur_y) {
        if (intervals[i][1] > cur_y) {
          cur_y = intervals[i][1];
        }
      } else {
        result.push_back(vector<int>{cur_x, cur_y});
        cur_x = intervals[i][0];
        cur_y = intervals[i][1];
      }
    }
    result.push_back(vector<int>{cur_x, cur_y});
    return result;
  }
};

/*
 * Runtime: 23 ms, faster than 36.91% of C++ online submissions for Merge Intervals.
Memory Usage: 14.2 MB, less than 81.62% of C++ online submissions for Merge Intervals.
*/

