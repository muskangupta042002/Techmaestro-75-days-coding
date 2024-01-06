class Solution {
     void findSubsetSum(int i, int[] nums, int N, int target, ArrayList<Integer> arr, Set<List<Integer>> ans){
         
        if(i>=N || target<0){
            
            
            return ;
        }if(target==0){ans.add(new ArrayList<>(arr));}
        // if(i>=)
        arr.add(nums[i]);
        findSubsetSum(i,nums,N,target-nums[i],arr,ans);
        arr.remove(arr.size()-1);
        findSubsetSum(i+1,nums,N,target,arr,ans);
    }
    public List<List<Integer>> combinationSum(int[] candidates, int target) {
        int sum=0,N=candidates.length;
        ArrayList<Integer> arr=new ArrayList<Integer>();
        List<List<Integer>> s=new  ArrayList<>();
        Set<List<Integer>> ans=new HashSet<>();
        findSubsetSum(0,candidates,N,target,arr,ans);
        
        s.addAll(ans);
        return s;
    }
}