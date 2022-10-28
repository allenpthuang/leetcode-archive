class Solution {
 public:
  int minSteps(string s, string t) {
    unordered_map<char, int> s_char_map;
    unordered_map<char, int> t_char_map;
    
    for (const auto& c : s) {
      s_char_map[c]++;
    }
    
    for (const auto& c : t) {
      t_char_map[c]++;
    }
    /*
    unordered_map<char, int> swap_map;
    for (const auto& m : s_char_map) {
      if (t_char_map[m.first] =! m.second) {
        swap_map[m.first] += t_char_map[m.first] - m.second;
      //} else if (t_char_map[m.first] < m.second) {
      //  swap_map[m.first] += m.second - t_char_map[m.first];
      }
    }
    */
    int op_counter = 0;
    
    for (char c = 'a'; c <= 'z'; c++) {
      op_counter += abs(s_char_map[c] - t_char_map[c]);
    }
    
    return abs(op_counter) / 2;
  }
};

/* Runtime: 88 ms, faster than 57.62% of C++ online submissions for Minimum Number of Steps to Make Two Strings Anagram.
 * Memory Usage: 16.8 MB, less than 18.14% of C++ online submissions for Minimum Number of Steps to Make Two Strings Anagram.
 */

