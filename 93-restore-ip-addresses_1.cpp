class Solution {
 private:
  bool is_valid_seg(string& cur_seg) {
    if (cur_seg.size() == 0) return false;
    if (cur_seg.size() > 1 && cur_seg[0] == '0') return false;
    int seg_num = stoi(cur_seg);
    if (seg_num > 255 || seg_num < 0) return false;
    return true;
  }

  void worker(vector<string>& result, vector<string>& cur_ip, const string& s,
              int cur_idx) {
    if (cur_idx == s.size()) {
      if (cur_ip.size() == 4) {
        string ip = "";
        for (const auto& seg : cur_ip) {
          ip += seg + ".";
        }
        ip.pop_back();
        result.push_back(ip);
        return;
      } else {
        return;
      }
    }
    
    for (int i = cur_idx; i < s.size(); i++) {
      string cur_seg = s.substr(cur_idx, i - cur_idx + 1);
      if (is_valid_seg(cur_seg)) {
        cur_ip.push_back(cur_seg);
        worker(result, cur_ip, s, i + 1);
        cur_ip.pop_back();
      } else {
        break;
      }
    }
  }
 public:
  vector<string> restoreIpAddresses(string s) {
    vector<string> result;
    vector<string> cur_ip;
    worker(result, cur_ip, s, 0);
    return result;
  }
};

/* Runtime: 9 ms, faster than 17.10% of C++ online submissions for Restore IP Addresses.
 * Memory Usage: 6.8 MB, less than 34.71% of C++ online submissions for Restore IP Addresses.
 */

