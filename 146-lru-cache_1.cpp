class LRUCache {
 private:
  unordered_map<int, int> cache;
  unordered_map<int, list<int>::iterator> pos;
  list<int> lru_keys;
  int capacity;
  
  void remove_key(int key) {
    auto it = pos[key];
    lru_keys.erase(it);
    pos.erase(key);
  }
  
  void add_key(int key) {
    lru_keys.push_front(key);
    pos[key] = lru_keys.begin();
  }

 public:
  LRUCache(int capacity) : capacity(capacity) {}

  int get(int key) {
    if (cache.count(key) == 0) {
      return -1;
    }
    // update lru_keys
    remove_key(key);
    add_key(key);
    
    return cache[key];
  }

  void put(int key, int value) {
    // if the key exists
    if (cache.count(key) > 0) {
      // erase from lru_keys
      remove_key(key);
      capacity++;
    } else if (capacity == 0) {  // cache is full
      // erase from lru_keys
      int key_to_evict = lru_keys.back();
      remove_key(key_to_evict);
      cache.erase(key_to_evict);
      capacity++;
    }
    cache[key] = value;
    // put back to lru_keys
    // capacity decreases again
    add_key(key);
    capacity--;
  }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
 
 /* TLE */
 