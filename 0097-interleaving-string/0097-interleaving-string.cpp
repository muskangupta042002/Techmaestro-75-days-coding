class Solution {
public:
 unordered_map<string, bool> mem;
    bool possibleWays(string s1, string s2, string s3, int i, int j, int k, int l1, int l2, int l3){
        if(k==l3){
            return (i==l1 && j==l2)? true: false;
        }
         string key=to_string(i)+'*'+to_string(j)+'*'+to_string(k);
        if(mem.find(key)!=mem.end())
        {
            return mem[key];
        }
        if(i==l1){
            return mem[key] = (s3[k]==s2[j]) ? possibleWays(s1,s2,s3,i,j+1,k+1,l1,l2,l3) : false;
        }
        if(j==l2){
            return mem[key] = (s3[k]==s1[i]) ? possibleWays(s1,s2,s3,i+1,j,k+1,l1,l2,l3) : false;
        }
        bool one=false, two=false;
        if(s1[i]==s3[k]){
            one=possibleWays(s1,s2,s3,i+1,j,k+1,l1,l2,l3);
        }
        if(s2[j]==s3[k]){
            two= possibleWays(s1,s2,s3,i,j+1,k+1,l1,l2,l3);
        }
        return mem[key] = one or two;
    }
    bool isInterleave(string s1, string s2, string s3) {
        int len1=s1.length();
        int len2=s2.length();
        int len3=s3.length();
        if(len3!=len1+len2)
        {
            return false;
        }
        return possibleWays(s1,s2,s3,0,0,0,len1,len2,len3);
    }
};
//two ways only start from s1 or s2
//aadbbcbca