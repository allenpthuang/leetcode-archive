class Solution {
 public:
  bool isPrime(int m) {
    if (m == 0 || m == 1) return false;
    for (int i = 2; i * i <= m; i++) {
      if (m % i == 0) return false;
    }
    return true;
  }
  int countPrimes(int n) {
    vector<bool> to_check(n, true);
    int cnt = 0;
    for (int i = 0; i < n; i++) {
      if (to_check[i]) {
        if (isPrime(i)) {
          cnt++;
          for (int j = 2; j * i < n; j++) {
            to_check[j*i] = false;
          }
        }
      }
    }
    return cnt;
  }
};

/* TLE */

