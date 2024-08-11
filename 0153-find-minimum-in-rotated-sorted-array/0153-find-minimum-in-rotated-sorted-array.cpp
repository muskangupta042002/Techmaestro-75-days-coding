class Solution {
public:
    int findMin(vector<int>& nums) {
        int n=nums.size();
        int l=0,r=n-1,ans=INT_MAX;
        while(l<=r){
            int mid=l+((r-l)>>1);

            if(nums[mid]>=nums[l]){ //left
                ans=min(ans,nums[l]);
                l=mid+1;
            }
            else if(nums[mid]<=nums[r]){
                ans=min(ans,nums[mid]);
                r=mid-1;
            }
            else{
                return nums[mid];
            }

        }
        return ans;

    }
};