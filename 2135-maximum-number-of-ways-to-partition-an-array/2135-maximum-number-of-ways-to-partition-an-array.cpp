class Solution {
public:
    int waysToPartition(vector<int>& nums, int k) {
        int n=nums.size();
        vector<long long> pre(n), suff(n);
        pre[0] = nums[0];
        suff[n-1] = nums[n-1];
        for(int i=1;i<n;i++){
            pre[i]=pre[i-1]+nums[i];
            suff[n-i-1]=suff[n-i]+nums[n-i-1];
        }

        unordered_map<long long, long long> left, right;
        long long ans=0;
        for(int i=0;i<n-1;i++){
            right[pre[i]-suff[i+1]]++;
        }
        if(right.count(0)) ans=right[0];
        for(int i=0;i<n;i++){
            int d=k-nums[i];
            long long count=0;
            if(left.count(d)) count+=left[d];
            if(right.count(-d)) count+=right[-d];
            ans=max(count,ans);
            if(i<n-1){
                long long k=pre[i]-suff[i+1];
                left[k]++; right[k]--;
                if(right[k]==0) right.erase(k);
            }

        }
        return ans;
    }
};
/*
2 -1 2
2 1  3
3 1  2

[1 1 1 1]
[1 2 3 4]
[4 3 2 1]
*/