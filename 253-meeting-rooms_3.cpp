class Solution {
 private:
  map<int, int> changes_at_times;  // time -> the positive of negative number of meeting room needs

 public:
  int minMeetingRooms(vector<vector<int>>& intervals) {
    for (const auto& interval : intervals) {
      changes_at_times[interval[0]]++;
      changes_at_times[interval[1]]--;
    }
    
    int cur_need = 0;
    int cur_max = 0;
    for (const auto& [time, change] : changes_at_times) {
      cur_need += change;
      cur_max = max(cur_max, cur_need);
    }
    
    return cur_max;
  }
};

/* Runtime: 54 ms, faster than 14.35% of C++ online submissions for Meeting Rooms II.
 * Memory Usage: 13.6 MB, less than 20.91% of C++ online submissions for Meeting Rooms II.
 */

