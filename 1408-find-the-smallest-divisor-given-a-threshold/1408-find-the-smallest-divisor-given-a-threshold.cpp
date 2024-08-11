class Solution {
public:
    int smallestDivisor(vector<int>& nums, int threshold) {
        int maxN=*max_element(nums.begin(),nums.end());
        int i=1;
       int h=threshold;
        while(i<=maxN){
            int mid=(i+maxN)/2;
            long long int sum=0;
            for(int j=0;j<nums.size();j++){
                sum +=ceil(double(nums[j])/double(mid));
            }
            
            cout<<sum;
            if(sum<=h){
                
               maxN=mid-1;
            }
            else {
                 i=mid+1;
                
            }
            
            
        }
        return i;
    }
};