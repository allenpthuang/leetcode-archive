class Solution:
  def daysBetweenDates(self, date1: str, date2: str) -> int:
    d1 = datetime.datetime.strptime(date1, '%Y-%m-%d')
    d2 = datetime.datetime.strptime(date2, '%Y-%m-%d')
    if d1 > d2:
      diff = d1 - d2
    else:
      diff = d2 - d1
      
    return diff.days

# Runtime: 56 ms, faster than 24.38% of Python3 online submissions for Number of Days Between Two Dates.
# Memory Usage: 13.9 MB, less than 60.19% of Python3 online submissions for Number of Days Between Two Dates.

