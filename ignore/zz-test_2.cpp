#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

class vectorHash {
 public:
  size_t operator() (const vector<int>& v) const {
    if (v.size() == 0) {
      return hash<int>() (0);
    }
    size_t result = hash<int>() (v[0]);
    for (int i = 1; i < v.size(); i++) {
      result ^= hash<int>() (v[i]);
    }
    return result;
  }
};

int main() {
  unordered_map<int, bool> m;
  unordered_map<vector<int>, bool, vectorHash> m2;
  return 0;
}

