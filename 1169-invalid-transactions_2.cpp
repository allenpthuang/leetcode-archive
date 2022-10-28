class Solution {
 private:
  class Transaction {
   public:
    string name;
    int time;
    int amount;
    string city;
    string orig_str;
    Transaction(string name_, int time_, int amount_, string city_, string orig_str_)
        : name(name_), time(time_), amount(amount_), city(city_), orig_str(orig_str_) {}
  };

 public:
  vector<string> invalidTransactions(vector<string>& transactions) {
    multimap<int, Transaction> trxns_by_time;  // time -> Transaction
    for (const auto& transaction : transactions) {
      stringstream ss(transaction);
      string name, time, amount, city;
      getline(ss, name, ',');
      getline(ss, time, ',');
      getline(ss, amount, ',');
      getline(ss, city);
      Transaction trxn(name, stoi(time), stoi(amount), city, transaction);
      trxns_by_time.insert(pair<int, Transaction>{trxn.time, trxn});
    }
    
    unordered_multimap<string, Transaction> names_of_trxns_in_win;  // name -> Transaction
    queue<Transaction> q;
    vector<string> invalid_trxns;
    for (const auto& trxn : trxns_by_time) {
      
      while (! q.empty() && trxn.first >= q.front().time + 60) {
        auto ret = names_of_trxns_in_win.equal_range(q.front().name);
        for (auto it = ret.first; it != ret.second; it++) {
          if (it->second.time == q.front().time) {
            names_of_trxns_in_win.erase(it);
          }
        }
        q.pop();
      }
      q.push(trxn.second);
      bool found = false;
      if (names_of_trxns_in_win.count(trxn.second.name) > 0) {
        auto ret = names_of_trxns_in_win.equal_range(trxn.second.name);
        for (auto it = ret.first; it != ret.second; it++) {
          if (it->second.city != trxn.second.city) {
            found = true;
            invalid_trxns.push_back(it->second.orig_str);
          }
        }
        if (found) {
          invalid_trxns.push_back(trxn.second.orig_str);
        }
      }
      names_of_trxns_in_win.insert(pair<string, Transaction>{trxn.second.name, trxn.second});
      if (! found && trxn.second.amount > 1000) {
        invalid_trxns.push_back(trxn.second.orig_str);
      }
    }
    return invalid_trxns;
  }
};

/* wrong answer */
/* ["alice,20,800,mtv","bob,50,1200,mtv","alice,20,800,mtv","alice,50,1200,mtv","alice,20,800,mtv","alice,50,100,beijing"] */

