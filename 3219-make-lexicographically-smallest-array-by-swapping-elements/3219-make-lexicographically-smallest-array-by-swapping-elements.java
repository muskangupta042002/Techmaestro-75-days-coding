class Solution {
    public int[] lexicographicallySmallestArray(int[] nums, int limit) {
        ArrayList<int []> arr = new ArrayList<>();
        int n=nums.length;
        for(int i=0;i<n;i++){
            arr.add(new int[2]);
            arr.get(i)[0]=nums[i];
            arr.get(i)[1]=i;
        }
        Collections.sort(arr, Comparator.comparingInt(i -> i[0]));
        int i=0, j=1;
        while(j<n){
            List<Integer> indexes=new ArrayList<>();
            indexes.add(arr.get(i)[1]);
            while(j<n && arr.get(j)[0]-arr.get(j-1)[0]<=limit){
                indexes.add(arr.get(j)[1]);
                j++;
            }
            Collections.sort(indexes);
            for(int k=0;k<j-i;k++){
                nums[indexes.get(k)]=arr.get(i+k)[0];
            }
            i=j;
            j++;
        }
        return nums;
    }
}