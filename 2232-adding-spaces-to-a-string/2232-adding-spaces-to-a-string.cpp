class Solution {
public:
    string addSpaces(string s, vector<int>& spaces) {
        int n=s.length();
        string p="";
        int m=spaces.size();
        int j=0;
        for(int i=0;i<n+m,j<m;i++)
        {
            if(i==spaces[j])
            {
                p+=" ";
                j++;
            }
            p+=s[i];
        }
        for(int i=spaces[m-1]+1;i<n;++i)
        {
            p+=s[i];
        }
        return p;
    }
};