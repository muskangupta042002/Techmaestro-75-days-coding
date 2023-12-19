Dutch National Flag algorithm sorts it in a way better by using three pointers
loww
mid
high
* All the elements less than low are zeros
* greaterthan highare 2s
* in between low and high are 1s
​
* a[mid]==0 swap(a[mid],a[low]) low++, mid++
​
* a[mid]==1 mid++
* a[mid]==2 swap(a[mid],a[high]) high--