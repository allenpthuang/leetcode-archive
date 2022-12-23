class Solution {
 public:
  int lengthOfLIS(vector<int>& nums) {
    vector<int> seq;
    for (const auto& num : nums) {
      if (seq.empty() || seq.back() < num) {
        seq.push_back(num);
      } else {
        auto it = lower_bound(seq.begin(), seq.end(), num);
        *it = num;
      }
    }
    return seq.size();
  }
};

/**
 * Idea: maintain a vector where elements are strictly increasing.
 * The resulting vector does not necessarily contain the exact
 * correct subsequence, but the length will be correct. For example,
 * nums = [10,9,2,5,3,7,101,18,5], the resulting vector will be
 * [2, 3, 5, 18]. It was originally [2, 3, 7, 101], then [2, 3, 7, 18]
 * and then finally [2, 3, 5, 18].
 * That is because the elements that come later will "overwrite" the 
 * previous ones. But it is not important, as we're just updating
 * some placeholder. Only the ones get to be appended to the end matter.
 */

