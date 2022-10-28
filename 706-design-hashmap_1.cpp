class MyHashMap {
 public:
  vector<vector<pair<int, int> > > hashtable;
  MyHashMap() {
    hashtable = vector<vector<pair<int, int> > >(10000, vector<pair<int, int> >());
  }

  void put(int key, int value) {
    int hash_key = key / 10000;
    for (auto& p : hashtable[hash_key]) {
      if (p.first == key) {
        p.second = value;
        return;
      }
    }
    hashtable[hash_key].push_back(pair<int, int>{key, value});
  }

  int get(int key) {
    int hash_key = key / 10000;
    for (const auto& p : hashtable[hash_key]) {
      if (p.first == key) {
        return p.second;
      }
    }
    return -1;
  }

  void remove(int key) {
    int hash_key = key / 10000;
    for (auto it = hashtable[hash_key].begin(); it != hashtable[hash_key].end(); it++) {
      if ((*it).first == key) {
        hashtable[hash_key].erase(it);
        return;
      }
    }
  }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */

/* Runtime: 139 ms, faster than 92.56% of C++ online submissions for Design HashMap.
 * Memory Usage: 60.6 MB, less than 57.23% of C++ online submissions for Design HashMap.
 */

