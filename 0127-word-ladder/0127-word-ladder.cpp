class Solution {
public:
    int ladderLength(string beginWord, string endWord,
                     vector<string>& wordList) {
        unordered_set<string> myset;
        bool isPresent = false; // Checks if endWord is present in Dict
        // Insert all words from Dict in myset
        for (auto word : wordList) {
            if (endWord.compare(word) == 0)
                isPresent = true;
            myset.insert(word); // Insert word in Dict
        }
        if (isPresent == false) // endWord is not present in Dict
            return 0;

        queue<pair<string,int>> q;
        q.push({beginWord,1});
        int ans = 1e9;

        while (!q.empty()) {
            int depth=q.front().second;

            string curr = q.front().first;
            q.pop();
            // check for all possible 1 depth words
            for (int i = 0; i < curr.length(); ++i) // For each index
            {
                string temp = curr;
                for (char c = 'a'; c <= 'z'; ++c) // Try all possible chars
                {
                    temp[i] = c;
                    if (curr.compare(temp) == 0)
                        continue; // Skip the same word
                    if (temp.compare(endWord) == 0)
                        ans=min(ans,depth+1);
                         // endWord found
                    if (myset.find(temp) != myset.end()) {
                        q.push({temp,depth+1});
                        myset.erase(temp);
                    }
                }
            }
        }
        return ans==1e9?0:ans;
    }
};