class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        auto cmp=[&](const vector<int>&a, const vector<int>&b){
            return a[1]<b[1];
        };
        sort(intervals.begin(),intervals.end(),cmp);
        
        int ans = 1,prev=intervals[0][1];
        for(int i=1;i<intervals.size();i++){
            if(intervals[i][0]>=prev){
                ans++;
                prev=intervals[i][1];
            }
        }
        return intervals.size()-ans;
       
    }
};

/*
[[1,100],[11,22],[1,11],[2,12]]
[1,11] [2,12] [11,22] [1,100]
*/