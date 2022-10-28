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
      if (! end_times.empty() && end_times.top() <= intervals[i][0]) {
         end_times.pop();
      } else {
        counter++;
      }
      end_times.push(intervals[i][1]);
    }
    return counter;
  }
};

/* Runtime: 18 ms, faster than 92.34% of C++ online submissions for Meeting Rooms II.
 * Memory Usage: 11.8 MB, less than 69.26% of C++ online submissions for Meeting Rooms II.
 */

