class Solution {
 public:
  vector<int> topKFrequent(vector<int>& nums, int k) {
    unordered_map<int, int> um;
    for (const auto& num : nums) {
      um[num]++;
    }
    
    priority_queue<pair<int, int> > pq;
    for (const auto& p : um) {
      pq.push(pair(p.second, p.first));
    }
    
    vector<int> result;
    for (int i = 0; i < k; i++) {
      result.push_back(pq.top().second);
      pq.pop();
    }
    
    return result;
  }
};

/* Runtime: 37 ms, faster than 5.35% of C++ online submissions for Top K Frequent Elements.
 * Memory Usage: 13.8 MB, less than 40.07% of C++ online submissions for Top K Frequent Elements.
 */

