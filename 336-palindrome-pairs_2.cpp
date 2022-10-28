class Solution {
 private:
  class WordTree {
   public:
    vector<WordTree*> dict;
    int orig_idx;
    WordTree() : dict(26, nullptr), orig_idx(-1) {}
  };
  WordTree* head;
  
  
 public:
  Solution() {
    head = new WordTree();
  }
  vector<vector<int>> palindromePairs(vector<string>& words) {
    for (int i = 0; i < words.size(); i++) {
      WordTree* cur_node = head;
      for (int j = words[i].size() - 1; j >= 0; j--) {
        if (cur_node->dict[words[i][j] - 'a'] == nullptr) {
          cur_node->dict[words[i][j] - 'a'] = new WordTree();
        }
        cur_node = cur_node->dict[words[i][j] - 'a'];
      }
      cur_node->orig_idx = i;
    }
    
    vector<vector<int> > results;
    for (int i = 0; i < words.size(); i++) {
      WordTree* cur_node = head;
      int char_cnt = 0;
      for (const auto& ch : words[i]) {
        if (cur_node->dict[ch - 'a'] == nullptr) {
          break;
        }
        char_cnt++;
        cur_node = cur_node->dict[ch - 'a'];
      }
      if (char_cnt != words[i].size()) {
        continue;
      }
      if (cur_node->orig_idx != -1 && cur_node->orig_idx != i) {
        results.push_back({cur_node->orig_idx, i});
      }
    }
    return results;
  }
};

/* wrong answer */

