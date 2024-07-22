class Solution {
public:

    int helper(vector<int>& nums) {
        int n=nums.size();
        //vector<int> dp(n);
        int prev=nums[n-1],prev2=0;
        for(int i=n-2;i>=0;i--){
            int pick=nums[i];
            if(i<n-2){
                pick+=prev2;
            }
            prev2=prev;
            prev=max(pick,prev);
        }
        return prev;
    }

    int rob(vector<int>& nums) {
        int n=nums.size();
        if(n==1){
            return nums[0];
        }
        vector<int> temp1, temp2;
        for(int i=0;i<n;i++){
            if(i!=0){
                temp1.push_back(nums[i]);
            }
            if(i!=n-1){
                temp2.push_back(nums[i]);
            }
        }
        return max(helper(temp1),helper(temp2));
    }
};
//i , n-i-1
/*
1 n-1
2 n
5 1 1 5 1 2
*/
