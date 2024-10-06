class Solution {
    public boolean areSentencesSimilar(String sentence1, String sentence2) {
        String[] sChar=sentence1.split(" ");
        String[] pChar=sentence2.split(" ");
        int i1=0, i2=0, n1=sChar.length, n2=pChar.length, j1=n1-1, j2=n2-1;
        if(n1>n2){
            return areSentencesSimilar(sentence2,sentence1);
        }
        while(i1<n1 && sChar[i1].equals(pChar[i1])){
                i1++;
            
        }
        while(j1>=0 && sChar[j1].equals(pChar[j2])){
            --j1;
            --j2;
        }
        return j1<i1;
        // Deque<String> deque1 = new ArrayDeque<>(Arrays.asList(sentence1.split(" ")));
        // Deque<String> deque2 = new ArrayDeque<>(Arrays.asList(sentence2.split(" ")));

        // while(!deque1.isEmpty() && !deque2.isEmpty() && deque1.peek().equals(deque2.peek())){
        //     deque1.poll();
        //     deque2.poll();
        // }
        // while(!deque1.isEmpty() && !deque2.isEmpty() && deque1.peekLast().equals(deque2.peekLast())){
        //     deque1.pollLast();
        //     deque2.pollLast();
        // }
        // return deque1.isEmpty() || deque2.isEmpty();
    }
}