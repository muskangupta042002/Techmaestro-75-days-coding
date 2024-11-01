class Solution {
public:
    string makeFancyString(string s) {
        int n=s.length();
        string ans="";
        ans+=s[0];
        for(int i=1;i<n-1;i++){
            if(s[i]==s[i-1] && s[i]==s[i+1] ){
                continue;
            }
            else{
                ans+=s[i];
            }
        }
        return n==1 ? ans: ans+s[n-1];
    }
};