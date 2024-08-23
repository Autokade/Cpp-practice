class Solution {
    public void moveZeroes(int[] nums) {
        int n = nums.length;
        int lastNonZeroFoundAt = 0;
        for (int i = 0; i <= n - 1; i++) {
            if (nums[i] != 0) {
                if (i != lastNonZeroFoundAt) {
                    int temp = nums[i];
                    nums[i] = nums[lastNonZeroFoundAt];
                    nums[lastNonZeroFoundAt] = temp;
                }
                lastNonZeroFoundAt++;
            }
        }

    }
}