class Solution {
 public:
  vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
    // courses are labeled from 0 to numCourses - 1
    // there are i prereq rules
    // prerequisites[i][0] means the desired course
    // prerequisites[i][1] means the prereq
    
    // it's a dag, ecah node's incomings are prereq's
    
    // store incoming degrees
    vector<int> in_degs(numCourses, 0);
    // store the courses that need the i-th course as prereq
    vector<vector<int> > deps(numCourses);
    for (const auto& p : prerequisites) {
      in_degs[p[0]]++;
      deps[p[1]].push_back(p[0]);
    }
    
    deque<int> dq;
    // start from the edge--the node without any incoming degrees
    for (int i = 0; i < in_degs.size(); i++) {
      if (in_degs[i] == 0) {
        dq.push_back(i);
      }
    }
    
    vector<int> result;
    while (! dq.empty()) {
      int cur_course = dq.front();
      dq.pop_front();
      result.push_back(cur_course);
      for (const auto& c : deps[cur_course]) {
        in_degs[c]--;
        if (in_degs[c] == 0) {
          dq.push_back(c);
        }
      }
    }
    if (result.size() != numCourses) {
      return vector<int>();
    } else {
      return result;
    }
  }
};

/* Runtime: 38 ms, faster than 43.37% of C++ online submissions for Course Schedule II.
 * Memory Usage: 13.2 MB, less than 90.12% of C++ online submissions for Course Schedule II.
 */
