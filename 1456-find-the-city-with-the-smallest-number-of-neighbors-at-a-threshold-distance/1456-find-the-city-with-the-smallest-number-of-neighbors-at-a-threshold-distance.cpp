class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        
        vector<vector<int>> matrix(n,vector<int>(n,1e9));
        for(auto it: edges){
            int u=it[0];
            int v=it[1];
            int w=it[2];
            matrix[u][v]=w;
            matrix[v][u]=w;
        }
	    for(int i=0;i<n;i++){
	       matrix[i][i]=0;
	    }
	    
	           
	   
	    for(int via=0;via<n;via++){
	        for(int i=0;i<n;i++){
	            for(int j=0;j<n;j++){
                    if(matrix[i][via]==1e9 || matrix[via][j]==1e9) continue;
	                matrix[i][j]=min(matrix[i][j], matrix[i][via]+matrix[via][j]);
	            }
	        }
	    }
        unordered_map<int,int> mp; int mini=n,index=-1;
	    for(int i=0;i<n;i++){
            int count=0;
	       for(int j=0;j<n;j++){
	           if(matrix[i][j]<=distanceThreshold){
	               count++;
	           }
	           
	       }
           if(count<=mini){
            mini=count;
            index=i;
           }
	    }
        return index;
        
        for(auto it: mp){
            if(it.second<mini){
                mini=it.second;
                if(it.first>index){
                    index=it.first;
                }
            }
        }
        return index;
    }
};