class TimeMap {
 private:
  unordered_map<string, vector<pair<string, int> > > m;
 public:
  TimeMap() {
    
  }
  
  void set(string key, string value, int timestamp) {
    pair<string, int> tmp_pair (value, timestamp);
    m[key].push_back(tmp_pair);
  }
  
  string get(string key, int timestamp) {
    string cur_value = "";
    int cur_timestamp = 0;
    for (const auto& p : m[key]) {
      if (timestamp >= p.second) {
        cur_value = p.first;
      }
    }
    return cur_value;
  }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */

/* TLE */

