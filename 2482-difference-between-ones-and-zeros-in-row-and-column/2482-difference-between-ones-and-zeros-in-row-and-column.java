class Solution {
    public int[][] onesMinusZeros(int[][] grid) {
        int m=grid.length;
        int n=grid[0].length;
        int[] row0=new int[m];
        int[] col0=new int[n];
        int[] row1=new int[m];
        int[] col1=new int[n];
        int[][] arr=new int[m][n];
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1){
                    row1[i]+=1;
                    col1[j]+=1;
                }
                else{
                    row0[i]+=1;
                    col0[j]+=1;
                }
            }
        }
        
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
               arr[i][j]=row1[i]+col1[j] -row0[i]-col0[j];
            }
        }
        return arr;
    }
}

