class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        vector<vector<int>> ans;
        priority_queue<pair<int,pair<int,int>>> pq;
        for(int i=0;i<points.size();i++){
            int dis=((points[i][0]*points[i][0])+(points[i][1]*points[i][1]));
            pq.push({dis,{points[i][0],points[i][1]}});
            if(pq.size()>k){
                pq.pop();
            }
        }

        while(k--){
            int x=pq.top().second.first, y=pq.top().second.second;
            ans.push_back({x,y});
            pq.pop();
        }
        return ans;
    }
};