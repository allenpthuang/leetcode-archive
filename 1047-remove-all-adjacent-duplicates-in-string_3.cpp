class Solution {
 public:
  string removeDuplicates(string s) {
    string result = "";
    for (const auto& c : s) {
      if (result.size() != 0) {
        if (c == result.back()) {
          result.pop_back();
        } else {
          result.push_back(c);
        }
      } else {
        result.push_back(c);
      }
    }
    return result;
  }
};

/* Runtime: 23 ms, faster than 74.55% of C++ online submissions for Remove All Adjacent Duplicates In String.
 * Memory Usage: 11 MB, less than 73.88% of C++ online submissions for Remove All Adjacent Duplicates In String.
 */

