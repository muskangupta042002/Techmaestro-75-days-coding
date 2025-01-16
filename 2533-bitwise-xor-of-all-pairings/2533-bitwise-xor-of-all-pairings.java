class Solution {
    

    public int xorAllNums(int[] nums1, int[] nums2) {
        int n = nums1.length, m = nums2.length, x = 0, y = 0;
        if (m % 2 != 0) {
            for (int i = 0; i < n; i++) {
                x ^= nums1[i];
            }
        }

        if (n % 2 != 0) {
            for (int i = 0; i < m; i++) {
                y ^= nums2[i];
            }
        }

        return x ^ y;
    }
}
