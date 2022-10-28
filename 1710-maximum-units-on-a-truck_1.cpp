class Solution {
 public:
  int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
    // The boxes take up the same volume so the more the units per box
    // the better. We wnat to use up the "denser" boxes first then.
    
    int result = 0;
    map<int, int, greater<int> > table; // (units_per_box, count_of_such_box)
    for (const auto& bt : boxTypes) {
      table[bt[1]] += bt[0];
    }
    for (auto& [unit, count] : table) {
      if (truckSize <= 0) {
        break;
      }
      if (count <= truckSize) {
        result += count * unit;
        truckSize -= count;
      } else {
        result += truckSize * unit;
        truckSize -= truckSize;
      }
    }
    return result;
  }
};

/* Runtime: 91 ms, faster than 42.20% of C++ online submissions for Maximum Units on a Truck.
 * Memory Usage: 17.7 MB, less than 30.27% of C++ online submissions for Maximum Units on a Truck.
 */

