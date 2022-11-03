class Solution {
 private:
  int fact(int n) {
     return (n == 0) || (n == 1) ? 1 : n * fact(n - 1);
  }

 public:
  int numPairsDivisibleBy60(vector<int>& time) {
    vector<int> mod_cnt(60, 0);
    for (const auto& t : time) {
      mod_cnt[t % 60]++;
    }
    int result = 0;
    if (mod_cnt[0] >= 2) {
      result = fact(mod_cnt[0]) / (2 * fact(mod_cnt[0] - 2));
    }
    cout << result << endl;
    for (int i = 1; i < mod_cnt.size() / 2; i++) {
      int cnt = mod_cnt[i] + mod_cnt[60 - i];
      if (cnt >= 2) {
        result += fact(cnt) / (fact(cnt - 2) * 2);
      }
    }
    return result;
  }
};

/* wrong answer */

