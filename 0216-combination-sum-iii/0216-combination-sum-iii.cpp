class Solution {
public:
    void helper(int i, int k, int target, set<vector<int>> &ans, vector<int>& temp) {
        if (target == 0 && k==0) {
                ans.insert(temp);
                return;
        }
        if (i > 9 || k==0) {
            return;
        }
        if (i <= target) {
            temp.push_back(i);
            helper(i + 1, k-1, target-i, ans, temp);
            temp.pop_back();
            helper(i + 1, k, target, ans, temp);
        }
        return;
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        set<vector<int>> ans;
        vector<int> temp;
        for (int i = 1; i <= 9; i++) {
            helper(i,k,n,ans,temp);
        }
        vector<vector<int>> res(ans.begin(),ans.end());
        return res;
    }
};