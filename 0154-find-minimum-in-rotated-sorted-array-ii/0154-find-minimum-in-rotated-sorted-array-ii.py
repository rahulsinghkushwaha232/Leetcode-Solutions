class Solution(object):
    def findMin(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        left, right = 0, len(nums) - 1

        while left < right:
            mid = (left + right) // 2

            # If mid element is greater than the rightmost, min is in the right half
            if nums[mid] > nums[right]:
                left = mid + 1
            # If mid element is less than the rightmost, min is at mid or in the left half
            elif nums[mid] < nums[right]:
                right = mid
            # When nums[mid] == nums[right], we can't be sure which side contains the minimum.
            # However, we can safely decrement 'right' because nums[right] is a duplicate 
            # of nums[mid] and we still have nums[mid] in the search space.
            else:
                right -= 1

        return nums[left]