class Solution {
 private:
  vector<int> working;
  vector<int> orig;
 public:
  Solution(vector<int>& nums) {
    orig = nums;
    working = orig;
  }

  vector<int> reset() {
    working = orig;
    return working;
  }
  
  vector<int> shuffle() {
    next_permutation(working.begin(), working.end());
    return working;
  }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * vector<int> param_1 = obj->reset();
 * vector<int> param_2 = obj->shuffle();
 */

/* wrong answer */

