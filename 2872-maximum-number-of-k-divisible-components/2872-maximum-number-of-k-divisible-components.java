class Solution {
    public int dfs(int node, int par, int ans[], List<List<Integer>> adj, int[] values, int k){
        int sum=values[node];
        for(Integer it:adj.get(node)){
            if(it!=par){
                sum+=dfs(it,node,ans,adj,values,k);
            }
        }
        if(sum%k==0){
            ans[0]++;
            return 0;
        }
        return sum;
    }
    public int maxKDivisibleComponents(int n, int[][] edges, int[] values, int k) {
        //adjacency list
        List<List<Integer>> adj=new ArrayList<>();
        for(int i=0;i<n;i++){
            adj.add(new ArrayList<>());
        }
        for(int i=0;i<edges.length;i++){
            adj.get(edges[i][0]).add(edges[i][1]);
            adj.get(edges[i][1]).add(edges[i][0]);
        }
        int ans[]=new int[1];
        dfs(0,-1,ans,adj,values,k);
        return ans[0];
        
    }
}