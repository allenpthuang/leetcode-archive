class Solution {
 public:
  vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
    // brute-force
    // k closest -> k smallest distant
    vector<pair<double, int> > point_dist(points.size());
    for (int i = 0; i < points.size(); i++) {
      point_dist[i].first = sqrt(pow(points[i][0], 2) + pow(points[i][1], 2));
      point_dist[i].second = i;
    }
    sort(point_dist.begin(), point_dist.end());
    vector<vector<int> > result(k);
    for (int i = 0; i < k; i++) {
      result[i] = points[point_dist[i].second];
    }
    return result;
  }
};

/* Runtime: 188 ms, faster than 99.01% of C++ online submissions for K Closest Points to Origin.
 * Memory Usage: 59.6 MB, less than 87.47% of C++ online submissions for K Closest Points to Origin.
 */

