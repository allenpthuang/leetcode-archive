class Solution {
 public:
  vector<int> topKFrequent(vector<int>& nums, int k) {
    unordered_map<int, int> m;
    for (const auto& num : nums) {
      m[num]++;
    }
    
    priority_queue<pair<int, int> > pq;
    for (const auto& e : m) {
      pq.push(pair<int, int>(e.second, e.first));
    }
    
    vector<int> result;
    for (int i = 0; i < k; i++) {
      result.push_back(pq.top().second);
      pq.pop();
    }
    return result;
  }
};

/* Runtime: 43 ms, faster than 5.12% of C++ online submissions for Top K Frequent Elements.
 * Memory Usage: 13.7 MB, less than 42.46% of C++ online submissions for Top K Frequent Elements.
 */

