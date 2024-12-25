class Solution {
    public int[] topKFrequent(int[] nums, int k) {
        Map<Integer,Integer> mp=new HashMap<>();
        for(int i:nums){
            mp.put(i,mp.getOrDefault(i,0)+1);
        }
        
        PriorityQueue<Integer> maxHeap=new  PriorityQueue<>((a,b) -> mp.get(b)-mp.get(a));
        for(int key:mp.keySet()){
            maxHeap.add(key);
        }
        
        int res[]=new int[k];
        for(int i=0;i<k;i++){
            res[i]=maxHeap.poll();
        }
        
        return res;
    }
}