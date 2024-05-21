combination 1 - 2^t *k
​
Reason: Assume if you were not allowed to pick a single element multiple times, every element will have a couple of options: pick or not pick which is 2^n different recursion calls, also assuming that the average length of every combination generated is k. (to put length k data structure into another data structure)
​
Why not (2^n) but (2^t) (where n is the size of an array)?
​
Assume that there is 1 and the target you want to reach is 10 so 10 times you can “pick or not pick” an element.
​
Space Complexity: O(k*x), k is the average length and x is the no. of combinations
​
​
​