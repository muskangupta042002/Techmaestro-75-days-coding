class Solution {
public:
    void helper(int i, vector<int>& nums, set<vector<int>> &ans,  vector<int> &temp){
        if(i>=nums.size()){
            ans.insert(temp);
            return;
        }
        temp.push_back(nums[i]);
        helper(i+1,nums,ans,temp);
        temp.pop_back();
         helper(i+1,nums,ans,temp);
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        set<vector<int>> ans;
        vector<int> temp;
        sort(nums.begin(),nums.end());
        helper(0,nums,ans,temp);
        vector<vector<int>> res(ans.begin(),ans.end());
        return res;
    }
};