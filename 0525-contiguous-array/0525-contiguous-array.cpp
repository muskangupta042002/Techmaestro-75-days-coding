class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int n=nums.size();
        unordered_map<int,int>mp;
        int pre[n];
        mp.insert({0,-1});
        int count=0;
        if(nums[0]==0){
            pre[0]=-1;
            mp.insert({pre[0],0});
        }
        else{
            pre[0]=1;mp.insert({pre[0],0});
        }
        for(int i=1;i<n;i++){
            if(nums[i]==0){
                pre[i]=pre[i-1]-1;
            }
            else{
                pre[i]=pre[i-1]+1;
            }
            int t=0;
            if(mp.find(pre[i])!=mp.end()){
                count=max(count,i-mp[pre[i]]);
            }
            else{
                mp.insert({pre[i],i});
            }
        }
        return count;
    }
};