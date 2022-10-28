class Solution {
 private:
  class Transaction {
   public:
    string name;
    int time;
    int amount;
    string city;
    string orig_str;
    bool city_invalid;
    bool amt_invalid;
    Transaction(string name_, int time_, int amount_, string city_, string orig_str_)
        : name(name_), time(time_), amount(amount_), city(city_), orig_str(orig_str_),
          city_invalid(false), amt_invalid(false) {}
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
            if (trxns[pre].city_invalid == true) {
              break;
            }
            trxns[pre].city_invalid = true;
          }
          pre--;
        }
        if (found) {
          trxns[i].city_invalid = true;
        }
        if (trxns[i].amount > 1000) {
          trxns[i].amt_invalid = true;
        }
      }
    }
    
    vector<string> result;
    for (const auto& [name, trxns] : name_trxns) {
      for (const auto& trxn : trxns) {
        if (trxn.city_invalid == true || trxn.amt_invalid == true) {
          result.push_back(trxn.orig_str);
        }
      }
    }
    
    return result;
  }
};

/* Runtime: 37 ms, faster than 85.67% of C++ online submissions for Invalid Transactions.
 * Memory Usage: 15.3 MB, less than 56.32% of C++ online submissions for Invalid Transactions.
 */

