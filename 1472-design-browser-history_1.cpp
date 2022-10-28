class BrowserHistory {
 private:
  vector<string> history;
  int ptr;

 public:
  BrowserHistory(string homepage) {
    history.push_back(homepage);
    ptr = 0;
  }

  void visit(string url) {
    if (ptr != history.size() - 1) {
      history.resize(ptr + 1);
    }
    history.push_back(url);
    ptr++;
  }

  string back(int steps) {
    if (ptr - steps < 0) {
      ptr = 0;
    } else {
      ptr -= steps;
    }
    return history[ptr]; 
  }

  string forward(int steps) {
    if (ptr + steps > history.size() - 1) {
      ptr = history.size() - 1;
    } else {
      ptr += steps;
    }
    return history[ptr];
  }
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */

/* Runtime: 309 ms, faster than 33.49% of C++ online submissions for Design Browser History.
 * Memory Usage: 57.5 MB, less than 79.23% of C++ online submissions for Design Browser History.
 */

