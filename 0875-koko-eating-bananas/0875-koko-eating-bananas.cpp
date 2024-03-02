class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
//         int maxN=*max_element(piles.begin(),piles.end());
//         int i=0;
//         //long long int ans=1000000009;
//         while(i<=maxN){
//             int mid=(i+maxN)/2;
//             long sum=0;
//             for(int i=0;i<piles.size();i++){
//                 sum +=ceil((double)piles[i] / (double)mid);
//             }
//             if(sum<=h){
                
//                 maxN=mid-1;
//             }
//             else{
//                 i=mid+1;
//             }
            
            
//         }
//         return i;
         auto it = max_element(piles.begin(), piles.end());
        int low = 1, high = *it;
        cout<<high;
        while (low <= high) {
            long hrs = 0;
            int mid = (low + high) / 2;
            for (int i = 0; i < piles.size(); i++) {
                hrs += ceil((double)piles[i] / (double)mid);
            }
            if (hrs <= h) {
                high = mid - 1;

            } else
                low = mid + 1;
        }
        return low;
    }
};