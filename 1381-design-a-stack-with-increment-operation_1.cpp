class CustomStack {
  public:
  vector<int> st;
  int max_size;
  CustomStack(int maxSize) {
    max_size = maxSize;
  }
  
  void push(int x) {
    if (st.size() < max_size) {
      st.push_back(x);
    }
  }
  
  int pop() {
    if (st.empty()) {
      return -1;
    } else {
      int tmp = st[st.size() - 1];
      st.erase(st.begin() + (st.size() - 1));
      return tmp;
    }
  }
  
  void increment(int k, int val) {
    for (int i = 0; i < k && i < st.size(); i++) {
      st[i] += val;
    }  
  }
};

/**
 * Your CustomStack object will be instantiated and called as such:
 * CustomStack* obj = new CustomStack(maxSize);
 * obj->push(x);
 * int param_2 = obj->pop();
 * obj->increment(k,val);
 */

/* Runtime: 38 ms, faster than 76.18% of C++ online submissions for Design a Stack With Increment Operation.
 * Memory Usage: 20.9 MB, less than 94.99% of C++ online submissions for Design a Stack With Increment Operation.
 */

