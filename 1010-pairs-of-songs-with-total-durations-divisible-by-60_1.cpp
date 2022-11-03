class Solution {
 public:
  int numPairsDivisibleBy60(vector<int>& time) {
    int result = 0;
    for (int i = 0; i < time.size(); i++) {
      for (int j = i + 1; j < time.size(); j++) {
        if ((time[i] + time[j]) % 60 == 0) {
          result++;
        }
      }
    }
    return result;
  }
};

/* Brute-force; TLE */

