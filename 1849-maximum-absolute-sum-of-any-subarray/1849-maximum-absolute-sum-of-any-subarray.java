class Solution {
    public int maxAbsoluteSum(int[] nums) {
        int maxSum = 0, minSum = 0;
        int currentMax = 0, currentMin = 0;
        
        for (int num : nums) {
            // Compute max subarray sum
            currentMax += num;
            maxSum = Math.max(maxSum, currentMax);
            if (currentMax < 0) currentMax = 0;

            // Compute min subarray sum
            currentMin += num;
            minSum = Math.min(minSum, currentMin);
            if (currentMin > 0) currentMin = 0;
        }
        
        return Math.max(maxSum, Math.abs(minSum));
    }
}
