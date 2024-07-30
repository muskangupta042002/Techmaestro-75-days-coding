class Solution {
public:
vector<int> v;
    Solution(vector<int>& w) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
        
        v.push_back(w[0]);
        for(int i=1;i<w.size();++i)
            v.push_back(v.back()+w[i]);    //Cumulative SUM
    }
    
    int pickIndex() {
        int low=0, high=v.size()-1;

        int random = (rand() % v.back()) + 1;
       while(low<=high){
        int mid=(low+high)/2;
        if(v[mid]==random){
            return mid;
        }
        else if(v[mid]<random){
            low=mid+1;
        }
        else{
            high=mid-1;
        }
       }
       return low;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(w);
 * int param_1 = obj->pickIndex();
 */