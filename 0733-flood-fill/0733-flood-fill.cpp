class Solution {
public:
    void dfs(int sr, int sc,vector<vector<int>>& image, int newColor, int oldColor){
        if(sr<0 || sc<0 || sr>=image.size() || sc>=image[0].size() || image[sr][sc]!=oldColor){
            return;
        }
        image[sr][sc]=newColor;
        
        dfs(sr+1,sc,image,newColor,oldColor);
        dfs(sr,sc-1,image,newColor,oldColor);
        dfs(sr,sc+1,image,newColor,oldColor);
        dfs(sr-1,sc,image,newColor,oldColor);
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        if(image[sr][sc]==color){
            return image;
        }
        
        dfs(sr,sc,image,color,image[sr][sc]);
        return image;
    }
};