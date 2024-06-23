class Solution {
public:
    bool isPresent(string p, vector<string>& wordDict){
        for(auto &a: wordDict){
            if(a==p){
                return true;
            }
        }
        return false;
    }
    bool helper(int index, string s, int n, vector<string>& wordDict, vector<int> &memo){
        if(index==n){
            return true;
        }
        if(memo[index]!=-1){return memo[index];}
        for(int i=index;i<n;i++){
            if(isPresent(s.substr(index,i-index+1),wordDict)){
                if(helper(i+1,s,n,wordDict,memo)) {
                    memo[index] = 0;
                    return true;
                }
            }
        }
        memo[index] = 0;
        return false;
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        int n=s.length(); vector<int> memo(n, -1);
        if(helper(0,s,n,wordDict,memo)){ return true;}
        return false;
    }
};