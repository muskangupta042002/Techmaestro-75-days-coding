class Solution {
    public String shiftingLetters(String s, int[][] shifts) {
        int len = s.length();
        int[] shiftArray = new int[len + 1];

        // Accumulate shifts
        for (int[] shift : shifts) {
            int start = shift[0];
            int end = shift[1];
            int direction = shift[2] == 0 ? -1 : 1;

            shiftArray[start] += direction;
            if (end + 1 < len) {
                shiftArray[end + 1] -= direction;
            }
        }

        // Compute the cumulative shift
        int cumulativeShift = 0;
        char[] result = s.toCharArray();

        for (int i = 0; i < len; i++) {
            cumulativeShift += shiftArray[i];
            int shift = ((cumulativeShift % 26) + 26) % 26; // Handle negative shifts

            // Shift the character
            result[i] = (char) ('a' + (result[i] - 'a' + shift) % 26);
        }

        return new String(result);
    }
}