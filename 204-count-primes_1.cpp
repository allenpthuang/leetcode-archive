class Solution {
 public:
  bool isPrime(int m) {
    if (m == 0 || m == 1) return false;
    for (int i = 2; i <= m/2; i++) {
      if (m % i == 0) return false;
    }
    return true;
  }
  int countPrimes(int n) {
    int cnt = 0;
    for (int i = 0; i < n; i++) {
      if (isPrime(i)) cnt++; 
    }
    return cnt;
  }
};

/* TLE */

