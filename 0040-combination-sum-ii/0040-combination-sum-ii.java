class Solution {
    void findSubsetSum(int i, int[] nums, int N, int target, ArrayList<Integer> arr, Set<List<Integer>> ans){
        
            if(target==0){
               ans.add(new ArrayList<>(arr));
                return;
            }
             
        for(int ind=i;ind<N;ind++){
            if(ind>i && nums[ind]==nums[ind-1]){continue;}
            if(nums[ind]>target){break;}
            
            arr.add(nums[ind]);
            findSubsetSum(ind+1,nums,N,target-nums[ind],arr,ans);
            arr.remove(arr.size()-1);
            
        }
        
        
    }
    public List<List<Integer>> combinationSum2(int[] candidates, int target) {
        int sum=0,N=candidates.length;
        Arrays.sort(candidates);
        ArrayList<Integer> arr=new ArrayList<Integer>();
        List<List<Integer>> s=new  ArrayList<>();
        Set<List<Integer>> ans=new HashSet<>();
        findSubsetSum(0,candidates,N,target,arr,ans);
        
        s.addAll(ans);
        
        return s;
    }
}