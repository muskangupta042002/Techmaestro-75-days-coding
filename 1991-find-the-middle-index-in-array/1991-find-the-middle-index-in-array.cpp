class Solution {
public:
    int findMiddleIndex(vector<int>& nums) {
        int n=nums.size();
        int pre[n],suf[n];
        pre[0]=nums[0];
        suf[n-1]=nums[n-1];
        for(int i=1;i<nums.size();i++){
            pre[i]=pre[i-1]+nums[i];
        }
        for(int i=n-2;i>=0;i--){
            suf[i]=suf[i+1]+nums[i];
        }
        for(int i=0;i<n;i++){
            if(pre[i]==suf[i]){
                return i;
            }
        }
        return -1;
    }
};