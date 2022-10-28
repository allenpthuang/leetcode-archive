class Solution {
 public:
  string removeDuplicates(string s) {
    string result = "";
    for (const auto& c : s) {
      if (result.size() == 0) {
        result.push_back(c);
      } else if (result.back() == c) {
        result.pop_back();
      } else {
        result.push_back(c);
      }
    }
    return result;
  }
};

/* Runtime: 55 ms, faster than 36.84% of C++ online submissions for Remove All Adjacent Duplicates In String.
 * Memory Usage: 10.8 MB, less than 72.76% of C++ online submissions for Remove All Adjacent Duplicates In String.
 */

