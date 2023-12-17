object Solution {
    def onesMinusZeros(grid: Array[Array[Int]]): Array[Array[Int]] = {
        val m=grid.length;
        val n=grid(0).length;
        val row0: Array[Int]=Array.fill(m)(0);
        val col0: Array[Int]=Array.fill(n)(0);
        val row1: Array[Int]=Array.fill(m)(0);
        val col1: Array[Int]=Array.fill(n)(0);
        
        //var arr = Array.ofDim [ Int ] ( m , n )
        for(i <- 0 until m){
            for(j <- 0 until n){
                if(grid(i)(j)==1){
                    row1(i)+=1
                    col1(j)+=1
                }
                else{
                    row0(i)+=1
                    col0(j)+=1
                }
            }
        }
        for(i <- 0 until m){
            for(j <- 0 until n){
                grid(i)(j)=row1(i)+col1(j)-row0(i)-col0(j);
            }
        }
        return grid;
    }
}
/*
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
*/