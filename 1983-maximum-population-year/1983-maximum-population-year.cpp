class Solution {
public:
    int maximumPopulation(vector<vector<int>>& logs) {
        map<int,int>mp;
        for(auto log: logs){
            mp[log[0]]++;
            mp[log[1]]--;

        }
        int count=0, maxCount=0, year;
        for(auto it: mp){
            count+=it.second;
            if(count>maxCount){
                maxCount=count;
                year=it.first;
            }
        }
        return year;
    }
};