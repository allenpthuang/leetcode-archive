class Solution {
 public:
  int jobScheduling(vector<int>& startTime,
                    vector<int>& endTime,
                    vector<int>& profit) {
    // create a vector of jobs
    // job[0]: endTime
    // job[1]: startTime
    // job[2]: profit
    vector<vector<int> > jobs(startTime.size());
    for (int i = 0; i < endTime.size(); i++) {
      jobs[i] = {endTime[i], startTime[i], profit[i]};
    }
    // sort it
    sort(jobs.begin(), jobs.end());
    
    // a map that maps endTime to profit
    map<int, int> dp;
    dp[0] = 0;
    
    // walk thru jobs
    for (const auto& job : jobs) {
      auto it = dp.upper_bound(job[1]);
      dp[job[0]] = max(dp.rbegin()->second, (--it)->second + job[2]);
    }
    
    return dp.rbegin()->second;
    
  }
};

/*
 * Runtime: 188 ms, faster than 44.92% of C++ online submissions for Maximum Profit in Job Scheduling.
Memory Usage: 63.7 MB, less than 37.34% of C++ online submissions for Maximum Profit in Job Scheduling.
*/

