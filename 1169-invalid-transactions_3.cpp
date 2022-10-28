class Solution {
 private:
  class Transaction {
   public:
    string name;
    int time;
    int amount;
    string city;
    string orig_str;
    int txn_id;
    Transaction(string name_, int time_, int amount_, string city_, string orig_str_, int txn_id_)
        : name(name_), time(time_), amount(amount_), city(city_), orig_str(orig_str_), txn_id(txn_id_) {}
  };

 public:
  vector<string> invalidTransactions(vector<string>& transactions) {
    multimap<int, Transaction> trxns_by_time;  // time -> Transaction
    int txn_id = 0;
    for (const auto& transaction : transactions) {
      stringstream ss(transaction);
      string name, time, amount, city;
      getline(ss, name, ',');
      getline(ss, time, ',');
      getline(ss, amount, ',');
      getline(ss, city);
      Transaction trxn(name, stoi(time), stoi(amount), city, transaction, txn_id++);
      trxns_by_time.insert(pair<int, Transaction>{trxn.time, trxn});
    }
    
    unordered_multimap<string, Transaction> names_of_trxns_in_win;  // name -> Transaction
    queue<Transaction> q;
    unordered_set<int> invalid_ids;
    for (const auto& trxn : trxns_by_time) {
      if (trxn.second.amount > 1000) {
        invalid_ids.insert(trxn.second.txn_id);
      }
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
            invalid_ids.insert(it->second.txn_id);
          }
        }
        if (found) {
          invalid_ids.insert(trxn.second.txn_id);
        }
      }
      names_of_trxns_in_win.insert(pair<string, Transaction>{trxn.second.name, trxn.second});
    }
    
    vector<string> invalid_trxns;
    for (const auto& trxn : trxns_by_time) {
      if (invalid_ids.count(trxn.second.txn_id) > 0) {
        invalid_trxns.push_back(trxn.second.orig_str);
      }
    }
    
    return invalid_trxns;
  }
};

/* runtime error: heap-use-after-free */
/* ["alex,676,260,bangkok","bob,656,1366,bangkok","alex,393,616,bangkok","bob,820,990,amsterdam","alex,596,1390,amsterdam"] */

