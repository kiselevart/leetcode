class Solution:
    def twoSum(self, nums: list[int], target: int) -> list[int]:
        diffs = {}
        for i in range(len(nums)):
            other_val = target - nums[i]
            if other_val in diffs: return [diffs[other_val], i]
            diffs[nums[i]] = i