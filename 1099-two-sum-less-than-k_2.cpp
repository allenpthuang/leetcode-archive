class Solution {
 public:
  int twoSumLessThanK(vector<int>& nums, int k) {
    vector<int> input = nums;
    sort(input.begin(), input.end());
    
    int cur_max = INT_MIN;
    int i = 0;
    int j = input.size() - 1;
    while (i < j) {
      if (input[i] + input[j] < k) {
        cur_max = max(cur_max, input[i] + input[j]);
        i++;
      } else {
        j--;
      }
    }
    if (cur_max == INT_MIN) {
      return -1;
    } else {
      return cur_max;
    }
  }
};


