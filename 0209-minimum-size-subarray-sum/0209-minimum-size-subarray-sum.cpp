class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int mini = 1e9;
 int sum = 0;
 int left = 0;
 for(int i=0;i<nums.size();i++){
     sum+=nums[i];
     while(left<nums.size() && sum>=target){
         mini = min(mini,(i-left+1));
         sum-=nums[left++];
     }
 }
 if(mini==1e9) return 0;
 else return mini;
    }
};