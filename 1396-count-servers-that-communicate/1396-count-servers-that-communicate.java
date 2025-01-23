class Solution {
    public int countServers(int[][] grid) {
        int m=grid.length, n=grid[0].length;
        int c1=0, c2=0;
        // HashSet<Integer> rs=new HashSet<>();
        // HashSet<Integer> cs=new HashSet<>();
        int[] r=new int[m];
        int[] c=new int[n];
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1){
                    c1++;
                    r[i]++;
                    c[j]++;
                }
            }
        }
        System.out.println(c1 + " m:" + m + " n:" + n + " ");
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1){
                    if(r[i]>1 || c[j]>1){
                        c2++;
                    }
                }
            }
        }
        return c2;
    }
}