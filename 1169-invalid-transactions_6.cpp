class Solution:
    def invalidTransactions(self, transactions: List[str]) -> List[str]:
        trans = [t.split(',') for t in transactions]
        result = []
        for i in range(len(trans)):
            name_i, time_i, amount_i, city_i = trans[i]
            if int(amount_i) > 1000:
                result.append(transactions[i])
                continue
            found = False 
            for j in range(len(trans)):
                if i == j:
                    continue
                name_j, time_j, amount_j, city_j = trans[j]
                if name_i == name_j and abs(int(time_i) - int(time_j)) <= 60 and city_i != city_j:
                    found = True
                    break
            if found:
                result.append(transactions[i])
        return result

"""
Runtime: 88 ms, faster than 84.74% of Python3 online submissions for Invalid Transactions.
Memory Usage: 14.7 MB, less than 39.98% of Python3 online submissions for Invalid Transactions.
"""

