class Solution {
 public:
  string removeDuplicates(string s, int k) {
    vector<pair<char, int> > st;  // char, count
    for (const auto& ch : s) {
      if (st.empty() || st.back().first != ch) {
        st.push_back({ch, 1});
      } else if (st.back().second == k - 1) {
        st.pop_back();
      } else {
        st.back().second++;
      }
    }
    string result = "";
    for (auto& [ch, count] : st) {
      for (; count > 0; count--) {
        result += ch;
      }
    }
    return result;
  }
};

/* Runtime: 20 ms, faster than 91.36% of C++ online submissions for Remove All Adjacent Duplicates in String II.
 * Memory Usage: 10.6 MB, less than 53.10% of C++ online submissions for Remove All Adjacent Duplicates in String II.
 */

