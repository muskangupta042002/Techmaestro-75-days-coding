class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        auto cmp = [&](const vector<int>& a, const vector<int>& b) {
            return a[1] < b[1];
        };
        sort(points.begin(), points.end(), cmp);
        int ans = 1, prev = points[0][1];
        for (int i = 1; i < points.size(); i++) {
            if (points[i][0] > prev) {
                ++ans;
                prev = points[i][1];
            }
        }
        return ans;
    }
};
