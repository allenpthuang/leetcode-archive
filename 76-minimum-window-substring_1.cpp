class Solution {
 public:
  string minWindow(string s, string t) {
    unordered_map<char, int> target;
    unordered_map<char, int> window;
    
    for (const auto& ch : t) {
      target[ch]++;
    }
    
    int satisfied = 0;
    int need = target.size();
    int left = 0;
    int cur_min_len = INT_MAX;
    string result = "";
    for (int right = 0; right < s.size(); right++) {
      char ch = s[right];
      window[ch]++;
      if (target.find(ch) != target.end()
          && window[ch] == target[ch]) {
        satisfied++;
      }
      
      while (satisfied == need) {
        if (right - left + 1 < cur_min_len) {
          cur_min_len = right - left + 1;
          result = s.substr(left, cur_min_len);
        }
        char to_pop = s[left];
        window[to_pop]--;
        if (target.find(to_pop) != target.end()
            && window[to_pop] < target[to_pop]) {
          satisfied--;
        }
        left++;
      }
    }
    return result;
  }
};

/* Runtime: 36 ms, faster than 51.39% of C++ online submissions for Minimum Window Substring.
 * Memory Usage: 16.7 MB, less than 10.02% of C++ online submissions for Minimum Window Substring. 
 */

