class Solution {
    // private int maxLen = 0; // Make maxLen a class variabl

    // private void helper(int i, int[] arr, int n, List<Integer> list) {
    //     if (i >= n)
    //         return;

    //     if (list.size() < 2) {
    //         list.add(arr[i]);
    //         helper(i + 1, arr, n, list);
    //         list.remove(list.size() - 1); // Backtrack
    //     } else {
    //         if (list.get(list.size() - 1) + list.get(list.size() - 2) == arr[i]) {
    //             list.add(arr[i]);
    //             maxLen = Math.max(maxLen, list.size()); // Update global maxLen
    //             helper(i + 1, arr, n, list);
    //             list.remove(list.size() - 1); // Backtrack
    //         }
    //     }

    //     // Explore without including arr[i] in the sequence
    //     helper(i + 1, arr, n, list);
    // }

    public int lenLongestFibSubseq(int[] arr) {
        // maxLen = 0;
        // helper(0, arr, arr.length, new ArrayList<>());
        // return maxLen >= 3 ? maxLen : 0; // Return 0 if no valid sequence


        // Set<Integer> s = new HashSet<>();
        // for(int x: arr){
        //     s.add(x);
        // }

        // int res=2;
        // for(int i=0;i<arr.length;i++){
        //     for(int j=i+1;j<arr.length;j++){
        //         int a= arr[i], b=arr[j], l=2;
        //         while(s.contains(a+b)){
        //             b=a+b; a=b-a; l++;
        //         }
        //         res=Math.max(res,l);
        //     }
        // }
        // return res>2 ? res : 0;

        // int n=arr.length;
        // int maxLen=0;
        // int[][] dp = new int[n][n];

        // Map<Integer, Integer> valToIdx = new HashMap<>();
        // for(int curr=0; curr<n; curr++){
        //     valToIdx.put(arr[curr], curr);
        //     for(int prev=0;prev<curr;prev++){
        //         int diff=arr[curr]-arr[prev];
        //         int prevIdx = valToIdx.getOrDefault(diff, -1);

        //         if(diff<arr[prev] && prevIdx >= 0){
        //             dp[prev][curr] = dp[prevIdx][prev]+1;
        //         }
        //         else{
        //             dp[prev][curr] = 2;
        //         }
        //          maxLen = Math.max(maxLen,dp[prev][curr]);
        //     }
           
        // }

        int n=arr.length;
        int maxLen=0;
        int[][] dp = new int[n][n];

        for(int curr=2; curr<n; curr++){
            int start = 0, end =curr-1;
            while(start<end){
                int sum=arr[start]+arr[end];
                if(sum>arr[curr]){
                    end--;
                }
                else if(sum<arr[curr]){
                    start++;
                }
                else{
                    dp[end][curr] = dp[start][end]+1;
                    maxLen = Math.max(dp[end][curr],maxLen);
                    end--;
                    start++;
                }
            }
        }
        return maxLen !=0? maxLen+2 : 0;
    }
}