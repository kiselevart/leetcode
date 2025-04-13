class Solution:
    def hasDuplicate(self, nums: list[int]) -> bool:
        counts = {}
        for num in nums:
            if counts.get(num): return True
            counts[num] = True
        
        return False