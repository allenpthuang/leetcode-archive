#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

int max_inversions(vector<int>& lst) {
  unordered_set<int> lst_set(lst.rbegin(), lst.rend());
  vector<int> ulst(lst_set.begin(), lst_set.end());
  int result = 0;
  
  for (int i = 0; i < ulst.size(); i++) {
    int l_cnt = 0;
    int r_cnt = 0;
    for (int j = i + 1; j < ulst.size(); j++) {
      if (ulst[i] > ulst[j]) r_cnt++;
    }

    for (int j = i - 1; j >= 0; j--) {
      if (ulst[i] < ulst[j]) l_cnt++;
    }
    result += l_cnt * r_cnt;
  }
  return result;
}

int main() {
  vector<int> input {4, 2, 2, 1};
  cout << max_inversions(input) << endl;
  return 0;
}

/* Unproven */
