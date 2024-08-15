class Solution {
public:

int lengthOfLongestSubstring(string s) {
    int n = s.length();
    int i = 0, j = 0;
    int maxi = 0;
    int mp[256] = {0}; // Array to store the last index of characters

    while (j < n) {
        if (mp[s[j]] == 0 || mp[s[j]]<i) {
            mp[s[j]] = j + 1; // Storing 1-based index to avoid conflict with
                              // default value 0
            maxi = max(maxi, j - i + 1);
            j++;
        } else {
            i = max(i, mp[s[j]]); // Move i to the index after the last
                                  // occurrence of s[j]
            mp[s[j]] = j + 1;
            j++;
        }
    }

    return maxi;
}
};