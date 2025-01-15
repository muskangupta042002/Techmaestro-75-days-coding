class Solution {
    public int minimizeXor(int num1, int num2) {
        int c1=0,c2=0,n1=num1,n2=num2;
        while(n1!=0){
            n1=n1&(n1-1);
            c1++;
        }
        while(n2!=0){
            n2=n2&(n2-1);
            c2++;
        }
        if(c1==c2){
            return num1;
        }
        else if(c1<c2) {
            int k=0;
            System.out.println(c1+","+c2);
            while(c1!=c2){
                if((num1&(1<<k))==0){
                    num1=num1|(1<<k);
                    c1++;
                    
                }
                k++;

            }
        }
        else{
             int k=0;
            System.out.println(c1+","+c2);
            while(c1!=c2){
                if((num1&(1<<k))!=0){
                    num1=num1&~(1<<k);
                    c1--;
                    
                }
                k++;

            }
        }
        return num1;
    }
}
/*
00110001
10001000
*/