class MyStack {
 private:
  queue<int> working;
  queue<int> tmp;

 public:
  MyStack() {

  }

  void push(int x) {
    working.push(x);
  }

  int pop() {
    while (working.size() > 1) {
      tmp.push(working.front());
      working.pop();
    }
    int popped = working.front();
    working.pop();
    
    swap(working, tmp);
    
    return popped;
  }

  int top() {
    int popped = pop();
    push(popped);
    return popped;
  }

  bool empty() {
    return working.empty();
  }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */

/* Runtime: 4 ms, faster than 28.30% of C++ online submissions for Implement Stack using Queues.
 * Memory Usage: 7 MB, less than 25.83% of C++ online submissions for Implement Stack using Queues.
 */

