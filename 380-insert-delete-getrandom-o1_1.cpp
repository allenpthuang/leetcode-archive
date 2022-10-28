class RandomizedSet {
 private:
  vector<int> pool;
  unordered_map<int, int> st_map;  // val -> idx to pool vector

 public:
  RandomizedSet() {

  }

  bool insert(int val) {
    if (st_map.find(val) != st_map.end()) {
      return false;
    }
    pool.push_back(val);
    st_map[val] = pool.size() - 1;
    return true;
  }

  bool remove(int val) {
    auto it = st_map.find(val);
    if (it == st_map.end()) {
      return false;
    }
    int idx = it->second;
    st_map.erase(it);
    
    if (idx == pool.size() - 1) {
      pool.pop_back();
      return true;
    }
    int back_val = pool[pool.size() - 1];
    st_map[back_val] = idx;
    pool[idx] = back_val;
    pool.pop_back();
    return true;
  }

  int getRandom() {
    return pool[rand() % pool.size()];
  }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */

/* Runtime: 475 ms, faster than 35.79% of C++ online submissions for Insert Delete GetRandom O(1).
 * Memory Usage: 97.2 MB, less than 20.95% of C++ online submissions for Insert Delete GetRandom O(1)
 */

