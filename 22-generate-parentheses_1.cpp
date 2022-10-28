class Solution {
 public:
  void worker(int n, unordered_set<string>& result, string cur_string) {
    string l = "()" + cur_string;
    string m = "(" + cur_string + ")";
    string r = cur_string + "()";
    if (n == 0) {
      result.insert(cur_string);
    } else if (cur_string.size() == 0) {
      worker(n - 1, result, l);
    } else {
      worker(n - 1, result, l);
      worker(n - 1, result, m);
      worker(n - 1, result, r);
    }
  }

  vector<string> generateParenthesis(int n) {
    unordered_set<string> result;
    string cur_string = "";
    worker(n, result, cur_string);
    vector<string> output(result.begin(), result.end());
    return output;
  }
};

/* wrong answer */

