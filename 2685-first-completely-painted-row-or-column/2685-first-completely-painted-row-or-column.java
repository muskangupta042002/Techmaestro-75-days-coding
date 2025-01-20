import java.util.*;

class Solution {
    public int firstCompleteIndex(int[] arr, int[][] mat) {
        int m = mat.length, n = mat[0].length;
        int[] rowF = new int[m];
        int[] colF = new int[n];
        int len = arr.length;

        // Map to store the position of each number in the matrix
        HashMap<Integer, int[]> mp = new HashMap<>();
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                mp.put(mat[i][j], new int[]{i, j});
            }
        }

        // Iterate over the array and update row/column counts
        for (int i = 0; i < len; i++) {
            int[] pos = mp.get(arr[i]);
            int r = pos[0];
            int c = pos[1];
            rowF[r]++;
            colF[c]++;
            if (rowF[r] == n || colF[c] == m) {
                return i;
            }
        }
        return -1; // Return -1 if no row or column is completely filled
    }
}
