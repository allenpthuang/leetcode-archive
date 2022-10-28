class Solution {
 public:
  vector<string> generatePalindromes(string s) {
    vector<string> result;
    vector<int> hist(26, 0);
    
    for (const auto& c : s) {
      hist[c - 'a']++;
    }
    
    int odd_idx = -1;
    // check if there are odd ones
    for (int i = 0; i < 26; i++) {
      if (hist[i] % 2 != 0) {
        if (s.size() % 2 == 0 || odd_idx != -1) {
          return result;
        } else {
          odd_idx = i;
        }
      }
    }
    
    // generate a string as the base
    string base_str = "";
    for (int i = 0; i < 26; i++) {
      if (i == odd_idx) {
        continue;
      }
      for (int j = 0; j < hist[i] / 2; j++) {
        base_str += i + 'a';
      }
    }
    if (odd_idx != -1) {
      int odd_cnt = hist[odd_idx];
      while (odd_cnt / 2 != 0) {
        base_str += odd_idx + 'a';
        odd_cnt -= 2;
      }
    }
    
    do {
      string whole_str = base_str + string(base_str.rbegin(), base_str.rend());
      if (odd_idx != -1) {
        whole_str.insert(whole_str.begin() + base_str.size(), odd_idx + 'a');
      }
      result.push_back(whole_str);
    } while (next_permutation(base_str.begin(), base_str.end()));
    
    return result;
  }
};

/* Runtime: 24 ms, faster than 98.70% of C++ online submissions for Palindrome Permutation II.
 * Memory Usage: 19.2 MB, less than 69.57% of C++ online submissions for Palindrome Permutation II.
 */

