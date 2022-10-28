class MinStack {
 private:
  stack<int> min_stack;
  stack<int> working_stack;

 public:
  MinStack() {
    
  }

  void push(int val) {
    if (min_stack.empty() || min_stack.top() >= val) {
      min_stack.push(val);
    }
    working_stack.push(val);
  }

  void pop() {
    if (working_stack.empty()) {
      return;
    }
    if (! min_stack.empty() && min_stack.top() == working_stack.top()) {
      min_stack.pop();
    }
    working_stack.pop();
  }

  int top() {
    if (! working_stack.empty()) {
      return working_stack.top();
    }
    return -1;
  }

  int getMin() {
    if (! min_stack.empty()) {
      return min_stack.top();
    }
    return -1;
  }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */

/* Runtime: 25 ms, faster than 87.31% of C++ online submissions for Min Stack.
 * Memory Usage: 16.4 MB, less than 31.20% of C++ online submissions for Min Stack.
 */

