/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode() {}
 *     TreeNode(int val) { this.val = val; }
 *     TreeNode(int val, TreeNode left, TreeNode right) {
 *         this.val = val;
 *         this.left = left;
 *         this.right = right;
 *     }
 * }
 */
class Solution {
    public void convert(TreeNode curr, int par, Map<Integer,Set<Integer>>mp){
        if(curr==null){
            return;
        }
        if(!mp.containsKey(curr.val)){
            mp.put(curr.val,new HashSet<>());
        }
        Set<Integer> adj=mp.get(curr.val);
        if(par!=0){
            adj.add(par);
        }
        if(curr.left!=null){
            adj.add(curr.left.val);
        }
        if(curr.right!=null){
            adj.add(curr.right.val);
        }
        convert(curr.left,curr.val,mp);
        convert(curr.right,curr.val,mp);
    }
    public int amountOfTime(TreeNode root, int start) {
        Map<Integer,Set<Integer>>mp=new HashMap<>();
        convert(root,0,mp);
        Queue<Integer>q=new LinkedList<>();
        q.add(start);
        int minute=0;
        Set<Integer>s=new HashSet<>();
        s.add(start);
        while(!q.isEmpty()){
            int size=q.size();
            while(size>0){
                int curr=q.poll();
               for(int num:mp.get(curr)){
                    if(!s.contains(num)){
                        q.add(num);
                        s.add(num);
                    }
               }
                size--;
            }
            minute++;
        }
            return minute-1;
    }
}