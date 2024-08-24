class MyCalendarTwo {
public:
    int count;
    map<int,int>mp;
    MyCalendarTwo() {
        count=2;
    }
    
    bool book(int start, int end) {
        mp[start]++;
        mp[end]--;
        int c=0;
        for(auto it:mp){
            c+=it.second;
            if(c>2){
                mp[start]--;
                mp[end]++;
                return false;
            }
        }
        return true;
    }
};

/**
 * Your MyCalendarTwo object will be instantiated and called as such:
 * MyCalendarTwo* obj = new MyCalendarTwo();
 * bool param_1 = obj->book(start,end);
 */