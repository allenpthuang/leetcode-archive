class Solution {
 public:
  vector<int> platesBetweenCandles(string s, vector<vector<int> >& queries) {
    vector<int> answer(queries.size(), 0);
    for (int i = 0; i < queries.size(); i++) {
      string cur_str = s.substr(queries[i][0], queries[i][1] - queries[i][0] + 1);
      int left_idx = -1;
      int right_idx = -1;
      for (int j = 0; j < cur_str.size(); j++) {
        if (cur_str[j] == '|') {
          left_idx = j;
          break;
        }
      }
      
      for (int j = cur_str.size() - 1; j >= 0; j--) {
        if (cur_str[j] == '|')  {
          right_idx = j;
          break;
        }
      }
      
      int plate_cnt = 0;
      if (right_idx > left_idx) {
        for (int k = left_idx + 1; k < right_idx; k++) {
          if (cur_str[k] == '*') plate_cnt++;
        }
      }
      answer[i] = plate_cnt;
    }
    return answer;
  }
};

/* TLE */

