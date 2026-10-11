class Solution {
    public int maxArea(int[] height) {
        int left = 0;
        int right = height.length - 1;
        int maxWater = 0;

        while (left < right) {
            // Width is the distance between the two pointers
            int width = right - left;
            
            // Height of the container is limited by the shorter line
            int h = Math.min(height[left], height[right]);
            
            // Calculate current area and update max
            int currentArea = width * h;
            maxWater = Math.max(maxWater, currentArea);

            // Move the pointer pointing to the shorter line
            if (height[left] < height[right]) {
                left++;
            } else {
                right--;
            }
        }

        return maxWater;
    }
}