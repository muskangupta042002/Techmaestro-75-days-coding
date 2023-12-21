class Solution {
    public int maxWidthOfVerticalArea(int[][] points) {
        Arrays.sort(points, (a,b) -> a[0] - b[0]);
        int maxi=0;
        int a=points[0][0];
        for(int i=1;i<points.length;i++){
            maxi=Math.max(maxi,points[i][0]-a);
            a=points[i][0];
        }
        return maxi;
    }
}
/*
Arrays.sort(myArr, (a, b) -> a[0] - b[0]);
 Return the widest vertical area
 between two points such that no points are inside the area.
 
 */