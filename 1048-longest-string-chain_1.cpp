class Solution {
 public:
  int longestStrChain(vector<string>& words) {
    //vector<unordered_map<char, int> > char_num_map(words.size());
    unordered_map<char, int> p_char_map;
    
    int cur_len = 1;
    int cur_max_len = 1;
    
    // get the first map
    for (const auto& c : words[0]) {
      p_char_map[c]++;
    }
    
    // create the following maps
    for (int i = 1; i < words.size(); i++) {
      unordered_map<char, int> n_char_map;
      for (const auto& c : words[i]) {
        n_char_map[c]++;
      }
      
      bool valid = false;
      for (const auto& m : p_char_map) {
        if (n_char_map[m.first] >= m.second) {
          valid = true;
        } else {
          valid = false;
          break;
        }
      }
      
      if (valid) {
        if (words[i - 1].size() + 1 != words[i].size()) {
          valid = false;
        }
      }
      
      if (valid) {
        cur_len++;
      } else {
        cur_max_len = max(cur_max_len, cur_len);
        cur_len = 1;
      }
      
      p_char_map = n_char_map;
    }
    
    return cur_max_len;
  }
};

/* Failed */

