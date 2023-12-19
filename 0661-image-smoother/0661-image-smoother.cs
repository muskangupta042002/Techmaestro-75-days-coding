public class Solution {
    public int[][] ImageSmoother(int[][] img) {
        // Save the dimensions of the image.
        int m = img.Length;
        int n = img[0].Length;

        // Create a new image of the same dimension as the input image.
        int[][] smoothImg = new int[m][];
        for (int i = 0; i < m; i++) {
            smoothImg[i] = new int[n];
        }

        // Iterate over the cells of the image.
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                // Initialize the sum and count 
                int sum = 0;
                int count = 0;

                // Iterate over all plausible nine indices.
                for (int x = i - 1; x <= i + 1; x++) {
                    for (int y = j - 1; y <= j + 1; y++) {
                        // If the indices form valid neighbor
                        if (0 <= x && x < m && 0 <= y && y < n) {
                            sum += img[x][y];
                            count += 1;
                        }
                    }
                }

                // Store the rounded down value in smoothImg[i][j].
                smoothImg[i][j] = sum / count;
            }
        }

        // Return the smooth image.
        return smoothImg;
    }
}