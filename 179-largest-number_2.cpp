class Solution {
 public:
  string largestNumber(vector<int>& nums) {
    vector<string> num_strs;
    for (const auto& n : nums) {
      num_strs.push_back(to_string(n));
    }
    
    sort(num_strs.begin(), num_strs.end(),
         [](string s1, string s2) {
           return (s1 + s2 > s2 + s1);
         });

    string result = "";
    for (const auto& s : num_strs) {
      result += s;
    }
    
    // trim '0'
    while (result.size() > 1 && result[0] == '0') {
      result.erase(result.begin());
    }
    return result;
  }
};

/* Runtime: 7 ms, faster than 85.75% of C++ online submissions for Largest Number.
 * Memory Usage: 11.3 MB, less than 54.22% of C++ online submissions for Largest Number.
 */

