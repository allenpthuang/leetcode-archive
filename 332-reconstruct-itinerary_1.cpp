class Solution {
 private:
  void worker(vector<string>& result, vector<bool>& used, vector<vector<string> >& tickets,
              string dep) {
    result.push_back(dep);
    if (result.size() == tickets.size() + 1) {
      return;
    }
    
    string cur_min_arr = "ZZZZ";
    int cur_min_idx = -1;
    for (int i = 0; i < tickets.size(); i++) {
      if (used[i]) continue;
      if (tickets[i][0] == dep && tickets[i][1] < cur_min_arr) {
        cur_min_arr = tickets[i][1];
        cur_min_idx = i;
      }
    }
    used[cur_min_idx] = true;
    worker(result, used, tickets, cur_min_arr);
  }

 public:
  vector<string> findItinerary(vector<vector<string>>& tickets) {
    vector<string> result;
    vector<bool> used(tickets.size(), false);
    worker(result, used, tickets, "JFK");
    return result;
  }
};

/* wrong answer */

