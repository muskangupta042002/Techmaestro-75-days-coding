class Solution {
    public int[] findThePrefixCommonArray(int[] A, int[] B) {
        int n = A.length;
        int[] ans = new int[n];
        HashSet<Integer> seen = new HashSet<>();
        int commonCount = 0;
        
        for (int i = 0; i < n; i++) {
            // Check if A[i] is already seen
            if (seen.contains(A[i])) {
                commonCount++;
            } else {
                seen.add(A[i]);
            }

            // Check if B[i] is already seen
            if (seen.contains(B[i])) {
                commonCount++;
            } else {
                seen.add(B[i]);
            }

            // Store the result for this prefix
            ans[i] = commonCount;
        }

        return ans;
    }
}