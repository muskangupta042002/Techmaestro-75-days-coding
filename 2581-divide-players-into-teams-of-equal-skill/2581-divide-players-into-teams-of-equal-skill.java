class Solution {
    public long dividePlayers(int[] skill) {
        Arrays.sort(skill);
        int i=1, n=skill.length;
        int j=n-2;
        long sum=skill[0]+skill[n-1];
        long ans=skill[0]*skill[n-1];
        while(i<j){
            long k=skill[i]+skill[j];
            if(k!=sum){
                return -1;
            }
            ans+=skill[i]*skill[j];
            i++; j--;
        }
        return ans;
    }
}