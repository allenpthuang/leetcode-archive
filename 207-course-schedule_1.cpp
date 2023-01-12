class Solution {
 private:
  vector<vector<int> > prereqs;
  vector<bool> qualified;
  vector<bool> visited;

  bool dfs(int cur_course) {
    // base case: if already qualified, return true.
    if (qualified[cur_course] == true) return true;
  
    // base case: if the cur_course requires no prereqs,
    // set it as qualified and return true.
    if (prereqs[cur_course].size() == 0) {
      qualified[cur_course] = true;
      return true;
    }

    // circular
    if (visited[cur_course] == true) return false;
    visited[cur_course] = true;

    // else we need to go through and walk the prereqs
    bool can_done = true;
    for (const auto& prereq : prereqs[cur_course]) {
      if (dfs(prereq) == false) {
        can_done = false;
      } else {
        qualified[prereq] = true;
      }
    }
    return can_done;
  }

 public:
  bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
    prereqs.resize(numCourses, vector<int>());
    qualified.resize(numCourses, false);
    visited.resize(numCourses, false);

    // build the prereqs dict
    for (const auto& prereq_pair : prerequisites) {
      int course = prereq_pair[0];
      int prereq = prereq_pair[1];
      prereqs[course].push_back(prereq);
    }

    // walk from course no. 0 to n - 1
    for (auto i = 0u; i < numCourses; i++) {
      if (dfs(i) == true) {
        qualified[i] = true;
      }
    }

    for (const auto& can_done : qualified) {
      if (can_done == false) return false;
    }
    return true;
  }
};

/**
 * Read the description: we have courses labeled from 0 to n - 1,
 * return true if we can take every of them.
 *
 * Idea: build a dict that maps a course no. to a list of prereq's
 * that the course needs. Keep another dict with whether a course
 * can be taken. A course that requires no prereq's naturally
 * can be taken without anything.
 * Walk from 0 to n - 1 and set the second dict to true or false.
 */

/* Runtime
22 ms
Beats
88.25%
Memory
13.7 MB
Beats
70.30%
*/

