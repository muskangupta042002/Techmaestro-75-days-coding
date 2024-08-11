class Solution {
public:
    int minDays(vector<int>& bloomDay, int m, int k) {
        int n = bloomDay.size();
        int minDays=-1;
        int maxN = *max_element(bloomDay.begin(), bloomDay.end());
        int i = *min_element(bloomDay.begin(), bloomDay.end());;

        while (i <= maxN) {
            int mid = (i + maxN) / 2;
            int ans = 0,c=0;
            for (int j = 0; j < bloomDay.size(); j++) {
                if (bloomDay[j] <= mid) {
                    c++;
                } else {
                    ans+=(c/k);
                    c = 0;
                }
            }
            ans+=(c/k);
            if (ans >= m) {
                minDays=mid;
                maxN = mid - 1;
            } else  {
                i = mid + 1;
                
            } 
        }
        return minDays;
    }
};