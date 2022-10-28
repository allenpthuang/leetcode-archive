class Solution {
 public:
  vector<int> topKFrequent(vector<int>& nums, int k) {
    unordered_map<int, int> hist;   // (num, count)
    for (const auto& num : nums) {
      hist[num]++;
    }
    
    priority_queue<pair<int, int> > max_heap;   // (count, num)
    for (const auto& elem : hist) {
      max_heap.push(pair<int, int>{elem.second, elem.first});
    }
    
    vector<int> result;
    for (int i = 0; i < k; i++) {
      result.push_back(max_heap.top().second);
      max_heap.pop();
    }
    
    return result;
  }
};

/* Runtime: 36 ms, faster than 18.59% of C++ online submissions for Top K Frequent Elements.
 * Memory Usage: 13.6 MB, less than 73.12% of C++ online submissions for Top K Frequent Elements.
 */

