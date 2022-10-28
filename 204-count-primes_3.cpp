class Solution {
 public:
  int countPrimes(int n) {
    vector<bool> prime(n, true);
    if (n == 0 || n == 1) return 0;
    prime[0] = false;
    prime[1] = false;
    for (int i = 2; i*i < n; i++) {
      if (prime[i]) {
        for (int j = i*i; j < n; j = j + i) {
          prime[j] = false;
        }
      }
    }
    return count(prime.begin(), prime.end(), true);
  }
};

/* Runtime: 749 ms, faster than 6.34% of C++ online submissions for Count Primes.
 * Memory Usage: 10.3 MB, less than 71.25% of C++ online submissions for Count Primes.
 */

