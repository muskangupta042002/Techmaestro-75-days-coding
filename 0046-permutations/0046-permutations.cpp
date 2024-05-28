class Solution {
public:
    void helper(int i, vector<int>&nums, vector<vector<int>>& ans,vector<int> &temp){
        if(i==nums.size()){
            ans.push_back(nums);
            return;
        }
        
        for(int a=i;a<nums.size();a++){
                swap(nums[a],nums[i]);
                helper(i+1,nums,ans,temp);
                swap(nums[i],nums[a]);
                //temp.pop_back();
        }
        
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> temp;
        helper(0,nums,ans,temp);
        
        return ans;
    }
};
/*
base ccondn - i>=n || temp.size==nums/.size

jo gya vo dubara na jaaye
*/