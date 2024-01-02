import java.util.*;

class Solution {
    public List<List<Integer>> findMatrix(int[] nums) {
        HashMap<Integer, Integer> mp = new HashMap<>();
        for (int i : nums) {
            mp.put(i, mp.getOrDefault(i, 0) + 1);
        }
        
        int maxi = 0;
        for (Integer i : mp.values()) {
            maxi = Math.max(maxi, i);
        }
        
        List<List<Integer>> li = new ArrayList<>();
        
        for (int i = 0; i < maxi; i++) {
            List<Integer> list = new ArrayList<>();
            for (Map.Entry<Integer, Integer> entry : mp.entrySet()) {
                if (entry.getValue() > 0) {
                    list.add(entry.getKey());
                    entry.setValue(entry.getValue() - 1);
                }
            }
            li.add(list);
        }
        return li;
    }
}
