class Solution {
public:
    int minAreaRect(vector<vector<int>>& points) {
        unordered_map<int, unordered_set<int>> mp;
        int n=points.size();
        for(auto point: points){
            mp[point[0]].insert(point[1]);
        }
        int min_area=INT_MAX;
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                int x1=points[i][0], y1=points[i][1];
                int x2=points[j][0], y2=points[j][1];
                if(x1!=x2 && y1!=y2){
                    if(mp[x1].find(y2)!=mp[x1].end() && mp[x2].find(y1)!=mp[x1].end()){
                        min_area=min(min_area,abs(x1-x2)*abs(y1-y2));
                    }
                }
            }
        }
        return min_area != INT_MAX ? min_area : 0;
    }
};
/*
when can we not create rectangle: return 0
- when all the points are on same line => row same
- or 3 points given -> kabhi ni banega

*/