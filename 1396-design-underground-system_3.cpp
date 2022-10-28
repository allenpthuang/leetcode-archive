class UndergroundSystem {
 private:
  // sta_name -> (check_ins, check_outs)
  // p.first: check_ins: id -> vec of check-in times
  // p.second: check_outs: id -> vec of check-out times
  unordered_map<string, pair<unordered_map<int, vector<int> >, unordered_map<int, vector<int> > > > ledge;

 public:
  UndergroundSystem() {
  }

  void checkIn(int id, string stationName, int t) {
    ledge[stationName].first[id].push_back(t);
  }

  void checkOut(int id, string stationName, int t) {
    ledge[stationName].second[id].push_back(t);
  }

  double getAverageTime(string startStation, string endStation) {
    unordered_map<int, vector<int> > check_ins = ledge[startStation].first;
    unordered_map<int, vector<int> > check_outs = ledge[endStation].second;
    int total_duration = 0;
    int total_user_cnt = 0;
    for (const auto& usr_chk_out : check_outs) {
      for (const auto& chk_out_time : usr_chk_out.second) {
        if (check_ins.count(usr_chk_out.first) > 0) {
          if (check_ins[usr_chk_out.first].size() == 0) continue;
          auto target = upper_bound(check_ins[usr_chk_out.first].begin(), check_ins[usr_chk_out.first].end(), chk_out_time);
          if (target != check_ins[usr_chk_out.first].begin()) {
            target--;
            total_duration += chk_out_time - *target;
            total_user_cnt++;
          }
        }
      }
    }
    return double(total_duration) / total_user_cnt;
  }
};

/**
 * Your UndergroundSystem object will be instantiated and called as such:
 * UndergroundSystem* obj = new UndergroundSystem();
 * obj->checkIn(id,stationName,t);
 * obj->checkOut(id,stationName,t);
 * double param_3 = obj->getAverageTime(startStation,endStation);
 */

/* 49/56 test cases */

