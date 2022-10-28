class Solution {
 public:
  string reverseWords(string s) {
    string result = "";
    string tmp;
    stringstream ss(s);
    while (ss >> tmp) {
      if (result == "") {
        result = tmp;
      } else {
        result = tmp + " " + result;
      }
    }
    return result;
  }
};

