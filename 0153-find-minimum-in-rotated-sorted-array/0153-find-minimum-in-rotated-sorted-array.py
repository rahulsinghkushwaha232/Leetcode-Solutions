class Solution(object):
    def findMin(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        left, right = 0, len(nums) - 1

        while left < right:
            mid = (left + right) // 2
            
            # If the element at mid is greater than the rightmost element,
            # it means the minimum element is in the right half.
            if nums[mid] > nums[right]:
                left = mid + 1
            else:
                # Otherwise, the minimum is at mid or in the left half.
                right = mid

        return nums[left]