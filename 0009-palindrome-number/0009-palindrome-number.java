class Solution {
    public boolean isPalindrome(int x) {
        // Special cases:
        // 1. Negative numbers are not palindromes (e.g., -121 -> 121-)
        // 2. If the last digit is 0, the first digit must also be 0 (only possible for x = 0)
        if (x < 0 || (x % 10 == 0 && x != 0)) {
            return false;
        }

        int reversedHalf = 0;
        // Reverse only the second half of the number
        while (x > reversedHalf) {
            reversedHalf = reversedHalf * 10 + x % 10;
            x /= 10;
        }

        // When length is odd, we can get rid of the middle digit by reversedHalf / 10
        // For example: for 12321, at the end of loop x = 12, reversedHalf = 123,
        // so reversedHalf / 10 = 12 which matches x.
        return x == reversedHalf || x == reversedHalf / 10;
    }
}