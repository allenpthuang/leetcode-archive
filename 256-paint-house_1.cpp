class Solution {
public:
    int minCost(vector<vector<int>>& costs) {
        auto n = costs.size();
        vector<vector<int> > dp(n, vector<int>(3, 0));
        dp[0][0] = costs[0][0];
        dp[0][1] = costs[0][1];
        dp[0][2] = costs[0][2];

        for (auto i = 1u; i < n; i++) {
            dp[i][0] = min(dp[i - 1][1], dp[i - 1][2]) + costs[i][0];
            dp[i][1] = min(dp[i - 1][0], dp[i - 1][2]) + costs[i][1];
            dp[i][2] = min(dp[i - 1][1], dp[i - 1][0]) + costs[i][2];
        }

        return min({dp[n - 1][0], dp[n - 1][1], dp[n - 1][2]});
    }
};

/* Runtime
12 ms
Beats
78%
Memory
10 MB
Beats
40.67%
*/

/*
costs = [[17,2,17],[16,16,5],[14,3,19]]
0: 1
1: 2
2: 1
dp[idx][color]

dp[2][0] = min(dp[1][1], dp[1][2]) + costs[2][0];
dp[2][1] = min(dp[1][0], dp[1][2]) + costs[2][1];
dp[2][2] ...

return min({dp[n - 1][0], dp[n - 1][1], dp[n - 1][2]});

*/

