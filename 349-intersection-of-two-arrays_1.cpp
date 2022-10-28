class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> num1_set(nums1.begin(), nums1.end());
        unordered_set<int> result_set;
        
        for (int num2 : nums2) {
            if (num1_set.find(num2) != num1_set.end()) {
                result_set.insert(num2);
            }
        }
        vector<int> result;
        for (int res : result_set) {
            result.push_back(res);
        }
        return result;
    }
};

/* fetched from the submitted code */

