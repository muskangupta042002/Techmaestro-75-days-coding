class Solution {
    public int longestMonotonicSubarray(int[] arr) {
        int n = arr.length;
        int ans = 1, c1 = 1, c2 = 1;
        for (int i = 1; i < n; i++) {
            if (arr[i] > arr[i - 1]) {
                c1++;
            } else {
                ans = Math.max(c1, ans);
                c1 = 1;
            }
        }
        ans = Math.max(c1, ans);
        for (int i = 0; i < n - 1; i++) {
            if (arr[i] > arr[i + 1]) {
                c2++;
            } else {
                ans = Math.max(c2, ans);
                c2 = 1;
            }
        }
        ans = Math.max(c2, ans);
        return ans;
    }

}