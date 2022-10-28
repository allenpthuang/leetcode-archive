class Solution {
 private:
  void worker(int course_no, unordered_map<int, vector<int> >& prereq, unordered_set<int>& taken,
              vector<int>& result, unordered_set<int>& seen) {
    if (taken.count(course_no) > 0) {
      return;
    }
    seen.insert(course_no);
    if (prereq.find(course_no) != prereq.end()) {
      for (const auto& c : prereq[course_no]) {
        if (taken.count(c) == 0 && seen.count(course_no) == 0) {
          worker(c, prereq, taken, result, seen);
        }
      }
    }
    taken.insert(course_no);
    result.push_back(course_no);
  }
 public:
  vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
    vector<int> result;
    
    // courses are labeled from 0 to numCourses - 1
    // there are i prereq rules
    // prerequisites[i][0] means the desired course
    // prerequisites[i][1] means the prereq
    
    unordered_map<int, vector<int> > prereq;
    for (const auto& p : prerequisites) {
      prereq[p[0]].push_back(p[1]);
    }
    
    unordered_set<int> seen;
    unordered_set<int> taken;
        
    for (int i = 0; i < numCourses; i++) {
      // course no = i
      worker(i, prereq, taken, result, seen);
    }
    // if not possible, return the empty vector
    return result;
  }
};

/* Wrong Answer */

