class Solution {
public:
int helper(vector<int>& nums,  long long int k){
        int stu=1;
        int n=nums.size();
        long long int curr=0;
        for(int i=0;i<n;i++){
            if(curr+nums[i]<=k){
             curr+=nums[i];
            }
            else {
                curr=nums[i];
                stu++;
            }
        }
        return stu;
    }
    int splitArray(vector<int>& nums, int k) {
        long long int l=0,r=0; int n=nums.size();
        for(int i=0;i<n;i++){
            l=max(l,(long long) nums[i]);
            r+=nums[i];
        }
        while(l<=r){
            long long int mid=(l+r)/2;
            if(helper(nums,mid)>k){
                l=mid+1;
            }
            else{
                r=mid-1;
            }
        }
        return l;
    }
};