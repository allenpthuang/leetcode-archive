class Solution {
 public:
  vector<string> commonChars(vector<string>& words) {
    // set to MAX so that we can find the minimum of freq
    vector<int> hist(26, INT_MAX);
    for (const auto& w : words) {
      // hist of a particular word
      vector<int> cur_hist(26, 0);
      for (const auto& c : w) {
        cur_hist[c - 'a']++;
      }
      // compare it with the global hist and store the min
      for (int i = 0; i < 26; i++) {
        hist[i] = min(hist[i], cur_hist[i]);
      }
    }
    
    // produce the result
    vector<string> result;
    for (int i = 0; i < 26; i++) {
      while (hist[i] > 0) {
        string c = "";
        c += i + 'a';
        result.push_back(c);
        hist[i]--;
      }
    }
    return result;
  }
};

/* Runtime: 16 ms, faster than 50.73% of C++ online submissions for Find Common Characters.
 * Memory Usage: 9.4 MB, less than 59.89% of C++ online submissions for Find Common Characters.
 */

