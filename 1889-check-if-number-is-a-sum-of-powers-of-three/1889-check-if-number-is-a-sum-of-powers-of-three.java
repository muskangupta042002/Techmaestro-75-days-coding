class Solution {
    public boolean helper(int power, int n) {
        if(n==0){
            return true;
        }
        if(Math.pow(3,power) > n){
            return false;
        }

        boolean addPower = helper(power+1,n-(int)Math.pow(3,power));
        boolean skipPower = helper(power+1,n);

        return addPower || skipPower;
    }
    public boolean checkPowersOfThree(int n) {
        return helper(0,n);
    }
}