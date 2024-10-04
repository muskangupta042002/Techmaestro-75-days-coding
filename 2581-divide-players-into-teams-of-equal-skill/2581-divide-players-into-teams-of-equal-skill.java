class Solution {
    public long dividePlayers(int[] skill) {
        // Arrays.sort(skill);
        // int i=1, n=skill.length;
        // int j=n-2;
        // long sum=skill[0]+skill[n-1];
        // long ans=skill[0]*skill[n-1];
        // while(i<j){
        //     long k=skill[i]+skill[j];
        //     if(k!=sum){
        //         return -1;
        //     }
        //     ans+=skill[i]*skill[j];
        //     i++; j--;
        // }
        // return ans;

        //Optmized 
        int n=skill.length;
        int totalSum=0;
        int[] skillFreq = new int[1001];
        for(int i: skill){
            totalSum+=i;
            skillFreq[i]++;
        }

        if(totalSum%(n/2) != 0) return -1;
        int target=((totalSum)/(n/2));
        long ans=0;
        for(int i: skill){
            int k=target-i;
            if(skillFreq[k]==0){
                return -1;
            }
            ans+=(long)k* (long)i;
            skillFreq[k]--;
        }
        //count pairs twice
        return ans/2;
    }
}