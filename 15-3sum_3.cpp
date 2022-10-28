class Solution {
 public:
  class vectorHash {
    public:
    size_t operator() (const vector<int>& v) const {
      if (v.size() == 0) {
        return hash<int>() (0);
      }
      size_t result = hash<int>() (v[0]);
      for (int i = 1; i < v.size(); i++) {
        result ^= hash<int>() (v[i]);
      }
      return result;
    }
  };

  vector<vector<int>> threeSum(vector<int>& nums) {
    vector<vector<int> > result;
    //bool used[3000] = {false};
    unordered_map<vector<int>, int, vectorHash> used_tuple;
    unordered_map<int, int> idx_map;
    for (int i = 0; i < nums.size(); i++) {
      idx_map[nums[i]] = i;
    }
    for (int i = 0; i < nums.size(); i++) {
      for (int j = 0; j < nums.size(); j++) {
        if (i == j) continue;
        int c = 0 - nums[i] - nums[j]; // c = 0 - a - b
        if (idx_map.count(c) > 0) {
          if (idx_map[c] != i && idx_map[c] != j) {
//              && ! (used[i] & used[j] && used[idx_map[c]])) {
//            used[i] = true;
//            used[j] = true;
//            used[idx_map[c]] = true;
            vector<int> tup{nums[i], nums[j], c};
            sort(tup.begin(), tup.end());
            if (used_tuple.count(tup) == 0) {
              result.push_back(vector<int>{nums[i], nums[j], c});
              used_tuple[tup]++;
            }
          }
        }
      }
    }
    return result;
  }
};

/* TLE * /
