class MyStack {
 private:
  queue<int>* old_q;
  queue<int>* new_q;

 public:
  MyStack() {
    old_q = new queue<int>();
    new_q = new queue<int>();
  }
  
  ~MyStack() {
    delete old_q;
    delete new_q;
  }
    
  void push(int x) {
    new_q->push(x);
  }
  
  int pop() {
    if (new_q->size() > 1) {
      old_q->push(new_q->front());
      new_q->pop();
    }
    int popped = new_q->front();
    new_q->pop();
    swap(new_q, old_q);
    return popped;
  }
    
  int top() {
    int top_elem = pop();
    push(top_elem);
    return top_elem;
  }
    
  bool empty() {
    return old_q->empty() && new_q->empty();
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

/* wrong answer */

