class MyQueue {
 private:
  stack<int> q;
  stack<int> tmp;

 public:
  MyQueue() {

  }
  
  void push(int x) {
    q.push(x);
  }
    
  int pop() {
    while (q.size() > 1) {
      tmp.push(q.top());
      q.pop();
    }
    int popped = q.top();
    q.pop();
    while (tmp.size() > 0) {
      q.push(tmp.top());
      tmp.pop();
    }
    return popped;
  }
    
  int peek() {
    while (q.size() > 1) {
      tmp.push(q.top());
      q.pop();
    }
    int peeked = q.top();
    while (tmp.size() > 0) {
      q.push(tmp.top());
      tmp.pop();
    }
    return peeked;
  }
    
  bool empty() {
    return q.empty();
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

/*Runtime: 3 ms, faster than 40.15% of C++ online submissions for Implement Queue using Stacks.
 * Memory Usage: 7.2 MB, less than 13.63% of C++ online submissions for Implement Queue using Stacks.
 */

