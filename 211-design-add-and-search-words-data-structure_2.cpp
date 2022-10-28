class WordDictionary {
 private:
  vector<vector<vector<bool> > > dict;
  vector<vector<bool> > temp_dict;
  void reset_temp_dict() {
    temp_dict = vector<vector<bool> > (25, vector<bool>(27, false));
  }

 public:
  WordDictionary() {
    temp_dict = vector<vector<bool> > (25, vector<bool>(27, false)); // last bit to check if modded
  }

  void addWord(string word) {
    reset_temp_dict();
    for (int i = 0; i < word.size(); i++) {
      temp_dict[i][word[i] - 'a'] = true;
      temp_dict[i][26] = true;
    }
    dict.push_back(temp_dict);
  }

  bool search(string word) {
    for (const auto& w : dict) {
      
      for (int i = 0; i < word.size(); i++) {
        if (w[i][26] == false) {
          break;
        }
        if (word[i] == '.'
            || w[i][word[i] - 'a'] == true) {
          if (i == word.size() - 1) {
            if (i + 1 < w.size() && w[i + 1][26] == true) {
              break;
            } else {
              return true;
            }
          }
          continue;
        } else {
          break;
        }
      }
    }
    return false;
  }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */

/* TLE */

