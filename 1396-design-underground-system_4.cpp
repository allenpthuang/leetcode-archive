class UndergroundSystem {
 private:
  unordered_map<int, pair<string, int> > check_ins;  // user_id -> (sta_name, time)
  // start_sta -> end_sta -> (trip_cnt, total_trip_duration)
  unordered_map<string, unordered_map<string, pair<int, int> > > trips;

 public:
  UndergroundSystem() {
  }

  void checkIn(int id, string stationName, int t) {
    check_ins[id] = {stationName, t};
  }

  void checkOut(int id, string stationName, int t) {
    auto check_in_entry = check_ins[id];
    trips[check_in_entry.first][stationName].first++;
    trips[check_in_entry.first][stationName].second += t - check_in_entry.second;
  }

  double getAverageTime(string startStation, string endStation) {
    return double(trips[startStation][endStation].second) / trips[startStation][endStation].first;
  }
};

/**
 * Your UndergroundSystem object will be instantiated and called as such:
 * UndergroundSystem* obj = new UndergroundSystem();
 * obj->checkIn(id,stationName,t);
 * obj->checkOut(id,stationName,t);
 * double param_3 = obj->getAverageTime(startStation,endStation);
 */

/* Runtime: 188 ms, faster than 80.36% of C++ online submissions for Design Underground System.
 * Memory Usage: 58.1 MB, less than 79.31% of C++ online submissions for Design Underground System.
 */

