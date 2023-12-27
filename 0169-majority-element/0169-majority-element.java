class Solution {
    public int majorityElement(int[] nums) {
        int n=nums.length;
        int count=1,prev=nums[0];
        for(int i=1;i<n;i++){
            if(prev==nums[i]){
                count++;
                
            }
            else{
                count-=1;
                
                if(count<0){count=1;prev=nums[i];}
            }
        }
        return prev;
    }
}
/*
count=1 prev=3
count=0 prev=3

count=1 prev=2
count=2 prev=2
count=1 prev=2
count=0 prev=2
count=1 prev=1 
count=0 prev=1
count=-1 prev*/
