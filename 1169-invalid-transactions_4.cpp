class Solution {
 private:
  class Transaction {
   public:
    string name;
    int time;
    int amount;
    string city;
    string orig_str;
    bool invalid;
    Transaction(string name_, int time_, int amount_, string city_, string orig_str_)
        : name(name_), time(time_), amount(amount_), city(city_), orig_str(orig_str_),
          invalid(false) {}
  };

 public:
  vector<string> invalidTransactions(vector<string>& transactions) {
    unordered_map<string, vector<Transaction> > name_trxns;
    for (const auto& transaction : transactions) {
      stringstream ss(transaction);
      string name, time, amount, city;
      getline(ss, name, ',');
      getline(ss, time, ',');
      getline(ss, amount, ',');
      getline(ss, city);
      Transaction trxn(name, stoi(time), stoi(amount), city, transaction);
      name_trxns[name].push_back(trxn);
    }
    
    for (auto& [name, trxns] : name_trxns) {
      sort(trxns.begin(), trxns.end(), [](const Transaction& lhs, const Transaction& rhs) {
        return lhs.time < rhs.time;
      });
    }
    
    for (auto& [name, trxns] : name_trxns) {
      for (int i = trxns.size() - 1; i >= 0; i--) {
        bool found = false;
        int pre = i - 1;
        while (pre >= 0 && trxns[pre].time + 60 >= trxns[i].time) {
          if (trxns[pre].city != trxns[i].city) {
            found = true;
            trxns[pre].invalid = true;
          }
          pre--;
        }
        if (found || trxns[i].amount > 1000) {
          trxns[i].invalid = true;
        }
      }
    }
    
    vector<string> result;
    for (const auto& [name, trxns] : name_trxns) {
      for (const auto& trxn : trxns) {
        if (trxn.invalid == true) {
          result.push_back(trxn.orig_str);
        }
      }
    }
    
    return result;
  }
};

/* Runtime: 59 ms, faster than 60.82% of C++ online submissions for Invalid Transactions.
 * Memory Usage: 15.5 MB, less than 54.07% of C++ online submissions for Invalid Transactions.
 */
 