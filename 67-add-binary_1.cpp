class Solution {
 public:
  string addBinary(string a, string b) {
    int l = max(a.size(), b.size());
    vector<int> calc (l + 1, 0);
    for (int i = a.size() - 1, j = 0; i >= 0; i--, j++) {
      calc[j] += a[i] - '0';
    }
    for (int i = b.size() - 1, j = 0; i >= 0; i--, j++) {
      calc[j] += b[i] - '0';
    }
    for (int i = 0; i < calc.size() - 1; i++) {
      while (calc[i] > 1) {
        calc[i] -= 2;
        calc[i+1] += 1;
      }
    }
    string output = "";
    for (int i = 0; i < calc.size(); i++) {
      if (i == calc.size() - 1 && calc[i] == 0) {
        continue;
      }
      output = to_string(calc[i]) + output;
    }
    return output;
  }
};

/* Runtime: 8 ms, faster than 18.28% of C++ online submissions for Add Binary.
 * Memory Usage: 7.1 MB, less than 11.02% of C++ online submissions for Add Binary.
 */

