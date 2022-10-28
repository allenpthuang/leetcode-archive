class WordDictionary {
 private:
  // vector<vector<bool> > dict;
  bool dict[25][27];
  

 public:
  WordDictionary() {
    // dict = vector<vector<bool> >(25, vector<bool>(27, false)); // last bit to check if modded
    memset(&dict, false, sizeof(bool) * 25 * 27);
  }

  void addWord(string word) {
    for (int i = 0; i < word.size(); i++) {
      dict[i][word[i] - 'a'] = true;
      dict[i][26] = true;
    }
  }

  bool search(string word) {
    for (int i = 0; i < word.size(); i++) {
      if (word[i] == '.') {
        if (dict[i][26] == true) {
          continue;
        } else {
          return false;
        }
      }
      if (dict[i][word[i] - 'a'] == true) {
        continue;
      }
      return false;
    }
    return true;
  }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */

/* wrong answer; could from different words!! */

