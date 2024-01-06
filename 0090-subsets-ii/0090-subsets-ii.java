class Solution {
    void findSubsetSum(int i, int[] nums, int N, ArrayList<Integer> arr, Set<List<Integer>> ans){
        if(i>=N){
            ans.add(new ArrayList<>(arr));
            return ;
        }
        arr.add(nums[i]);
        findSubsetSum(i+1,nums,N,arr,ans);
        arr.remove(arr.size()-1);
        findSubsetSum(i+1,nums,N,arr,ans);
    }
    public List<List<Integer>> subsetsWithDup(int[] nums) {
        int N=nums.length;Arrays.sort(nums);
        ArrayList<Integer> arr=new ArrayList<Integer>();
        Set<List<Integer>> ans=new HashSet<>();
        findSubsetSum(0,nums,N,arr,ans);
        List<List<Integer>> s=new  ArrayList<>();
        s.addAll(ans);
        return s;
    }
}