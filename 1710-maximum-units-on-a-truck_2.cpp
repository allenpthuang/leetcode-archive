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
    for (const auto& [unit, count] : table) {
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

/* Runtime: 41 ms, faster than 96.43% of C++ online submissions for Maximum Units on a Truck.
 * Memory Usage: 17.6 MB, less than 30.74% of C++ online submissions for Maximum Units on a Truck.
 */

