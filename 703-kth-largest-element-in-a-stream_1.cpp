class KthLargest {
 private:
  int heap_size;
  priority_queue<int, vector<int>, greater<int> > min_heap;
  void add_to_heap(int val, int k) {
    if (min_heap.size() < k) {
      min_heap.push(val);
    } else if (val > min_heap.top()) {
      min_heap.pop();
      min_heap.push(val);
    }
  }

 public:
  KthLargest(int k, vector<int>& nums) : heap_size(k) {
    for (const auto& num : nums) {
      add_to_heap(num, heap_size);
    }
  }

  int add(int val) {
    add_to_heap(val, heap_size);
    return min_heap.top();
  }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */

/* Runtime: 32 ms, faster than 97.00% of C++ online submissions for Kth Largest Element in a Stream.
 * Memory Usage: 19.9 MB, less than 59.90% of C++ online submissions for Kth Largest Element in a Stream.
 */

