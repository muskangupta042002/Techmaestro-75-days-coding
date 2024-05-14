class Solution {
public:
    void findSubsequence(int i, vector<int>& nums, vector<vector<int>>&ans, vector<int>&temp){
        if(i>=nums.size()){
            ans.push_back(temp);
           // temp.erase();
            return;
        }
        temp.push_back(nums[i]);
        findSubsequence(i+1,nums,ans,temp);
        temp.pop_back();
        findSubsequence(i+1,nums,ans,temp);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> temp;
        findSubsequence(0,nums,ans,temp);
        return ans;
    }
};