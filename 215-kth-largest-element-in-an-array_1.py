class Solution:
    def findKthLargest(self, nums: List[int], k: int) -> int:
        nums.sort(reverse=True)
        return nums[k - 1]

'''
Runtime: 82 ms, faster than 26.86% of Python3 online submissions for Kth Largest Element in an Array.
Memory Usage: 15.2 MB, less than 47.45% of Python3 online submissions for Kth Largest Element in an Array.
'''

