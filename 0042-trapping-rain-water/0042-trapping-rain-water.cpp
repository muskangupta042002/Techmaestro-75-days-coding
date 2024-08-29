class Solution {
public:
    int trap(vector<int>& height) {
        int n=height.size();
        int ans=0;
        vector<int> preMax(n,0), postMax(n,0);
        preMax[0]=height[0], postMax[n-1]=height[n-1];
        for(int i=1;i<n;i++){
            preMax[i]=max(preMax[i-1],height[i]);
        }
        for(int i=n-2;i>=0;i--){
            postMax[i]=max(postMax[i+1],height[i]);
        }
        for(int i=0;i<n;i++){
            int temp=min(preMax[i],postMax[i]);
            ans+=temp-height[i];
        }
        return ans;
    }
};
/*
[0,1,0,2,1,0,1,3,2,1,2,1]
 3,3,3,3,3,3,3,3,2,2,2,1
 0,1,1,2,2,2,2,3,3,3,3,3

   0+1+0+1+2+1+0+0+1+0+0
*/