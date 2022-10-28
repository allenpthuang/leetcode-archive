class Solution {
 public:
  vector<string> topKFrequent(vector<string>& words, int k) {
    unordered_map<string, int> hist;
    for (const auto& w : words) {
      hist[w]++;
    }
    
    map<int, priority_queue<string, vector<string>, greater<string> > > table;
    for (const auto& h : hist) {
      table[h.second].push(h.first);
    }
    
    vector<string> result;
    for (auto it = table.rbegin(); it != table.rend(); it++) {
      while (! (*it).second.empty()) {
        if (result.size() >= k) return result;
        result.push_back((*it).second.top());
        (*it).second.pop();
      }
    }
    
    return result;
  }
};

/* Runtime: 29 ms, faster than 18.72% of C++ online submissions for Top K Frequent Words.
 * Memory Usage: 12.7 MB, less than 52.66% of C++ online submissions for Top K Frequent Words.
 */

