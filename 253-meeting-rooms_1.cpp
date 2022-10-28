class Solution {
 private:
  priority_queue<int, vector<int>, greater<int> > end_times;

 public:
  int minMeetingRooms(vector<vector<int>>& intervals) {
    if (intervals.size() <= 1) {
      return 1;
    }
    sort(intervals.begin(), intervals.end());
    end_times.push(intervals[0][1]);
    int counter = 1;
    for (int i = 1; i < intervals.size(); i++) {
      int cur_start_time = intervals[i][0];
      int cur_end_time = intervals[i][1];
      if (! end_times.empty() && end_times.top() <= cur_start_time) {
         end_times.pop();
      } else {
        counter++;
      }
      end_times.push(cur_end_time);
    }
    return counter;
  }
};

/* Runtime: 29 ms, faster than 60.15% of C++ online submissions for Meeting Rooms II.
 * Memory Usage: 11.7 MB, less than 85.85% of C++ online submissions for Meeting Rooms II.
 */

