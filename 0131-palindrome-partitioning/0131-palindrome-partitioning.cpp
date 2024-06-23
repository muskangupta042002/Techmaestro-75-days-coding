class Solution {
public:
    bool isPalindrome(int i, int j, string s){
        //int i=0, n=s.length(), j=n-1;
        while(i<j){
            if(s[i]!=s[j]){
                return false;
            }
            i++;j--;
        }
        return true;
    }
    void solve(int index, string s, vector<vector<string>>&ans, vector<string>&temp){
        int n=s.length();
        if(index==n){
            ans.push_back(temp);
            return;
        }
        for(int i=index;i<n;i++){
            if(isPalindrome(index,i,s)){
                temp.push_back(s.substr(index,i-index+1));
                solve(i+1,s,ans,temp);
                temp.pop_back();
            }
            
        }
    }
    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        int n=s.length();
        vector<string> temp;
        solve(0,s,ans,temp);
        
        return ans;
    }
};