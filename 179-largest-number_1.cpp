class Solution {
 public:
  string largestNumber(vector<int>& nums) {
    vector<string> num_strs;
    for (const auto& n : nums) {
      num_strs.push_back(to_string(n));
    }
    
    sort(num_strs.rbegin(), num_strs.rend());
    // 92, 9899, hence wrong!
    sort(num_strs.rbegin(), num_strs.rend(),
         [](string s1, string s2) {
           return (s1[0] == s2[0]) && (s1.size() > s2.size());
         });
    string result = "";
    for (const auto& s : num_strs) {
      result += s;
    }
    return result;
  }
};

/* wrong answer */
