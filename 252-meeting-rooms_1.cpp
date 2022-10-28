class Solution {
 public:
  bool canAttendMeetings(vector<vector<int>>& intervals) {
    if (intervals.size() <= 1) {
      return true;
    }
    sort(intervals.begin(), intervals.end());
    for (int i = 0; i < intervals.size() - 1; i++) {
      int cur_end_time = intervals[i][1];
      int next_start_time = intervals[i + 1][0];
      if (cur_end_time > next_start_time) {
        return false;
      }
    }
    return true;
  }
};

/* Runtime: 34 ms, faster than 43.17% of C++ online submissions for Meeting Rooms.
 * Memory Usage: 11.7 MB, less than 77.92% of C++ online submissions for Meeting Rooms.
 */

