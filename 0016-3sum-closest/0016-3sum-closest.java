import java.util.Arrays;

class Solution {
    public int threeSumClosest(int[] nums, int target) {
        Arrays.sort(nums);
        int closestSum = nums[0] + nums[1] + nums[2];

        for (int i = 0; i < nums.length - 2; i++) {
            int left = i + 1;
            int right = nums.length - 1;

            while (left < right) {
                int currentSum = nums[i] + nums[left] + nums[right];

                // If current sum is closer to target than closestSum, update closestSum
                if (Math.abs(target - currentSum) < Math.abs(target - closestSum)) {
                    closestSum = currentSum;
                }

                if (currentSum < target) {
                    left++; // Increase sum by moving left pointer right
                } else if (currentSum > target) {
                    right--; // Decrease sum by moving right pointer left
                } else {
                    return currentSum; // Exact match found
                }
            }
        }

        return closestSum;
    }
}