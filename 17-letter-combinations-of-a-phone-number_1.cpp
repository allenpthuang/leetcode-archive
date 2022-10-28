class Solution {
 private:
  void worker(vector<string>& result, string& cur_str, const string pad[10],
              const vector<int>& input, int cur_key, int k) {
    if (input.size() == 0) return;
    if (k == 0) {
      result.push_back(cur_str);
      return;
    }
    
    for (int i = cur_key; i < input.size(); i++) {
      for (const auto& c : pad[input[i]]) {
        cur_str += c;
        worker(result, cur_str, pad, input, i + 1, k - 1);
        cur_str.pop_back();
      }
    }
  }
 public:
  vector<string> letterCombinations(string digits) {
    string pad[10] = {
      "", // 0
      "", // 1
      "abc",
      "def",
      "ghi",
      "jkl",
      "mno",
      "pqrs",
      "tuv",
      "wxyz"
    };

    vector<int> input;
    for (const auto& d : digits) {
      input.push_back(d - '0');
    }
    
    vector<string> result;
    string cur_str = "";
    
    worker(result, cur_str, pad, input, 0, input.size());
    
    return result;
    
  }
};

/* Runtime: 0 ms, faster than 100.00% of C++ online submissions for Letter Combinations of a Phone Number.
 * Memory Usage: 6.5 MB, less than 61.16% of C++ online submissions for Letter Combinations of a Phone Number.
 */

