class MyQueue {
 private:
  stack<int> working;
  stack<int> tmp;

 public:
  MyQueue() {

  }

  void push(int x) {
    working.push(x);
  }

  int pop() {
    while (! working.empty()) {
      tmp.push(working.top());
      working.pop();
    }
    int peeked = tmp.top();
    tmp.pop();
    while (! tmp.empty()) {
      working.push(tmp.top());
      tmp.pop();
    }
    return peeked;
  }

  int peek() {
    while (! working.empty()) {
      tmp.push(working.top());
      working.pop();
    }
    int peeked = tmp.top();
    while (! tmp.empty()) {
      working.push(tmp.top());
      tmp.pop();
    }
    return peeked;
  }

  bool empty() {
    return working.empty();
  }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */

/* Runtime: 0 ms, faster than 100.00% of C++ online submissions for Implement Queue using Stacks.
 * Memory Usage: 6.9 MB, less than 89.61% of C++ online submissions for Implement Queue using Stacks.
 */

