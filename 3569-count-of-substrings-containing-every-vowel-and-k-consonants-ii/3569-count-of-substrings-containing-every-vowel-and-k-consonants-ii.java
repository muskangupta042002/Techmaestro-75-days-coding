class Solution {
    private boolean isVowel(char c) {
        if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') {
            return true;
        }
        return false;
    }

    public long countOfSubstrings(String word, int k) {
        int n = word.length();

        HashMap<Character, Integer> vowelCount = new HashMap<>();
        int[] nextCon = new int[n];
        int nextConIndex = n;
        for (int i = n - 1; i >= 0; i--) {
            nextCon[i] = nextConIndex;
            if (!isVowel(word.charAt(i))) {
                nextConIndex = i;
            }
        }
        int i = 0, j = 0, c = 0, v = 0;
        long ans = 0;
        while (i <= j && j < n) {
            if (isVowel(word.charAt(j))) {
                vowelCount.put(word.charAt(j), vowelCount.getOrDefault(word.charAt(j), 0) + 1);
            } else {
                c++;
            }

            while (c > k) {
                char start = word.charAt(i);
                if (isVowel(start)) {
                    vowelCount.put(start, vowelCount.get(start)-1);
                    if (vowelCount.get(start) == 0) {
                        vowelCount.remove(start);
                    }
                } else {
                    c--;
                }
                i++;
            }

            while (i < n && vowelCount.keySet().size() == 5 && c == k) {
                ans += nextCon[j] - j;
                char start = word.charAt(i);
                if (isVowel(start)) {
                    vowelCount.put(start, vowelCount.get(start)-1);
                    if (vowelCount.get(start) == 0) {
                        vowelCount.remove(start);
                    }
                } else {
                    c--;
                }
                i++;
            }
            j++;
        }
        return ans;
    }
}