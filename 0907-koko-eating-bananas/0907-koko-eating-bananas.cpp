class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int maxN=*max_element(piles.begin(),piles.end());
        int i=1;
        //long long int ans=1000000009;
        while(i<=maxN){
            int mid=(i+maxN)/2;
            long sum=0;
            for(int j=0;j<piles.size();j++){
                sum +=ceil((double)piles[j] / (double)mid);
            }
            if(sum<=h){
                
                maxN=mid-1;
            }
            else{
                i=mid+1;
            }
            
            
        }
        return i;
    }
};