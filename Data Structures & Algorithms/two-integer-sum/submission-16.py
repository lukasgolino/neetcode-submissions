class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        return list(next((i, nums.index(target - num, i + 1)) for i, num in enumerate(nums) if (target - num) in nums[i+1:]))
        