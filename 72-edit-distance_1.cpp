class Solution {
 public:
  int minDistance(string word1, string word2) {
    // distance = diff_of_word_length + len(word2) - len(max_common_substr)
    int diff = word1.size() - word2.size();
    
    /*
    map<char, int> m1;
    map<char, int> m2;
    for (const auto& ch : word1) {
      m1[ch]++;
    }
    for (const auto& ch : word2) {
      m2[ch]++;
    }
    
    auto it_2 = m2.begin();
    for (auto it_1 = m1.begin();
          it_1 != m1.end() && it_2 != m2.end(); it_1++) {
      if (it_1->first == it_2->first)
    }
    */
    
    int idx_w1 = 0;
    int common_count = 0;
    for (const auto& ch : word2) {
      for (int i = idx_w1; i < word1.size(); i++) {
        if (word1[i] == ch) {
          idx_w1 = i + 1;
          common_count++;
          break;
        }
      }
    }
    return abs(diff) + word2.size() - common_count;
  }
};

/* wrong answer */

