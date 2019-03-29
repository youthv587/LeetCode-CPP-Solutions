class Solution(object):
    def arrayPairSum(self, nums):
        L = sorted(nums)
        x = 0
        length = len(L)
        for i in range(length):
            if i % 2 == 0:
                x += L[i]
        return x