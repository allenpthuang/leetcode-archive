class Solution {
 public:
  bool canConstruct(string ransomNote, string magazine) {
    // use a vector for even faster perf.
    vector<int> hist(26, 0);
    
    // count magazine
    for (const auto& c : magazine) {
      hist[c - 'a']++;
    }
    
    // substract char used in ransomNote
    for (const auto& c : ransomNote) {
      hist[c - 'a']--;
      if (hist[c - 'a'] < 0) {
        return false;
      }
    }
    
    return true;
  }
};

/* Runtime: 16 ms, faster than 79.54% of C++ online submissions for Ransom Note.
 * Memory Usage: 8.9 MB, less than 40.05% of C++ online submissions for Ransom Note.
 */

