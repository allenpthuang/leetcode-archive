class WordDictionary {
 private:
  class TreeNode {
   public:
    vector<TreeNode*> children;
    bool is_an_end;
    TreeNode() : children(vector<TreeNode*>(26, nullptr)), is_an_end(false) {}
  };
  
  TreeNode* head;
  bool tree_search(TreeNode* cur_node, string word) {
    for (int i = 0; i < word.size(); i++) {
      if (word[i] == '.') {
        for (const auto& next_node : cur_node->children) {
          if (next_node != nullptr && tree_search(next_node, word.substr(i + 1))) {
            return true;
          }
        }
        return false;
      }
      if (cur_node->children[word[i] - 'a'] == nullptr) {
        return false;
      }
      cur_node = cur_node->children[word[i] - 'a'];
    }
    return cur_node != nullptr && cur_node->is_an_end;
  }

 public:
  WordDictionary() {
    head = new TreeNode();
  }

  void addWord(string word) {
    TreeNode* cur_node = head;
    for (const auto& ch : word) {
      if (cur_node->children[ch - 'a'] == nullptr) {
        cur_node->children[ch - 'a'] = new TreeNode();
      }
      cur_node = cur_node->children[ch - 'a'];
    }
    cur_node->is_an_end = true;
  }

  bool search(string word) {
    return tree_search(head, word);
  }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */

/* TLE */

