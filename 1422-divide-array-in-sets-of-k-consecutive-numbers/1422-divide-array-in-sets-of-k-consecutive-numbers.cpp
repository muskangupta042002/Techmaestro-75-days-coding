class Solution {
public:
    bool isPossibleDivide(vector<int>& nums, int k) {
        if(k==1) return true;
        int n = nums.size();
        if (n % k != 0) {
            return false;
        }
        priority_queue<pair<int, int>, vector<pair<int, int>>,
                       greater<pair<int, int>>>
            pq;

        sort(nums.begin(), nums.end());
        for (int i = 0; i < n; i++) {
            if (pq.size() == 0) {
                pq.push({nums[i] + 1, 1});
            } else {
                int need = pq.top().first;
                int sz = pq.top().second;
                int curr = nums[i];
                if (need < curr)
                    return false;
                if (need > curr)
                    pq.push({curr + 1, 1});
                else if (need == curr) {
                    pq.pop();
                    if (sz + 1 == k) {
                        continue;
                    }
                    pq.push({curr + 1, sz + 1});
                }
            }
        }
        if (pq.size() == 0)
            return true;
        return false;
    }
};