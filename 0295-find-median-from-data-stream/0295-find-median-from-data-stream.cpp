class MedianFinder {
public:
    priority_queue<int> maxq;
    priority_queue<int, vector<int>, greater<int>> minq;
    int total;
    MedianFinder() { total = 0; }

    void addNum(int num) {
        if (maxq.size() == 0) {
            maxq.push(num);
            total++;
            return;
        }
        if (total % 2 != 0) {
            if (maxq.top() > num) {
                int k = maxq.top();
                maxq.pop();
                minq.push(k);
                maxq.push(num);
            } else {
                minq.push(num);
            }
        } else {
            if (maxq.top() < num && minq.top()<num) {
                int k = minq.top();
                minq.pop();
                minq.push(num);
                maxq.push(k);
            } else {
                maxq.push(num);
            }
        }
        total++;
    }

    double findMedian() {

        if (total % 2 != 0) {
            return (double)maxq.top();
        }
        double median = ((double)maxq.top() + (double)minq.top()) / 2.0;
        return median;
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */