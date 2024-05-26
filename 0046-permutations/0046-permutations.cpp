class Solution {
public:
    void helper(vector<int>&nums, vector<vector<int>>& ans,vector<int> &temp, vector<int>&freq){
        if(temp.size()==nums.size()){
            //empvector<int>t(temp.begin(),temp.end());
            ans.push_back(temp);
            return;
        }
        for(int a=0;a< nums.size();a++){
            if(freq[a]==0){
                 freq[a]=1;
                temp.push_back(nums[a]);
                helper(nums,ans,temp,freq);
                temp.pop_back();
                freq[a]=0;
            }
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> temp;
      vector<int>freq(nums.size(),0);
            helper(nums,ans,temp,freq);
            
        
        
        return ans;
    }
};
/*
base ccondn - i>=n || temp.size==nums/.size

jo gya vo dubara na jaaye
*/