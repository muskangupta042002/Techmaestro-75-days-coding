class Solution {
    public static void sortbyColumn(int arr[][], int col)
    {
        // Using built-in sort function Arrays.sort with lambda expressions
      
      Arrays.sort(arr, (a, b) -> Integer.compare(a[col],b[col])); // increasing order
        
    }
    public int minGroups(int[][] intervals) {
        int []line = new int[1000005];
        int maxEle = -1;

        for(int i=0;i<intervals.length;i++){
            int start = intervals[i][0], end = intervals[i][1];
            line[start]+=1;
            line[end+1]-=1;
        }
        for(int i=1;i<1000001;i++){
            line[i]+=line[i-1];
            maxEle = Math.max(maxEle, line[i]);
        }
        return maxEle;
    }
}
