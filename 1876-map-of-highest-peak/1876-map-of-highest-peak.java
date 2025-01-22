class Solution {
    public int[][] highestPeak(int[][] isWater) {
        int m = isWater.length, n = isWater[0].length;
        int[][] mat = new int[m][n];
        boolean[][] vis = new boolean[m][n];
        Queue<int[]> q = new LinkedList<>();

        // Initialize the queue with water cells and mark them as visited
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (isWater[i][j] == 1) { // Water cells
                    q.add(new int[] {i, j});
                    vis[i][j] = true;
                } else {
                    mat[i][j] = -1; // Mark land cells initially
                }
            }
        }

        // Directions for 4-connected neighbors
        int[] dx = {0, 1, -1, 0};
        int[] dy = {1, 0, 0, -1};

        // Perform BFS to calculate the heights
        while (!q.isEmpty()) {
            int[] current = q.poll();
            int row = current[0];
            int col = current[1];

            for (int i = 0; i < 4; i++) {
                int r = row + dx[i];
                int c = col + dy[i];

                // Check boundaries and if the cell is unvisited
                if (r >= 0 && c >= 0 && r < m && c < n && !vis[r][c]) {
                    mat[r][c] = mat[row][col] + 1; // Update height
                    q.add(new int[] {r, c});
                    vis[r][c] = true; // Mark as visited
                }
            }
        }

        return mat;
    }
}