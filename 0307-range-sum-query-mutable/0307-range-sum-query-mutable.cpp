class NumArray {

    vector<int> segTree;
    //vector<int> nums;
    int n;
    
    // Helper function to construct the segment tree
    void constructSegmentTree(vector<int>& segTree, vector<int>& nums, int low, int high, int pos) {
        if (low == high) {
            segTree[pos] = nums[low];
            return;
        }
        int mid = (low + high) / 2;
        constructSegmentTree(segTree, nums, low, mid, 2 * pos + 1);
        constructSegmentTree(segTree, nums, mid + 1, high, 2 * pos + 2);
        segTree[pos] = segTree[2 * pos + 1] + segTree[2 * pos + 2];
    }
    
    // Helper function to update the segment tree
    void updateSegmentTree(int index, int val, int low, int high, int pos) {
        if (low == high) {
            segTree[pos] = val;
            return;
        }
        int mid = (low + high) / 2;
        if (index <= mid) {
            updateSegmentTree(index, val, low, mid, 2 * pos + 1);
        } else {
            updateSegmentTree(index, val, mid + 1, high, 2 * pos + 2);
        }
        segTree[pos] = segTree[2 * pos + 1] + segTree[2 * pos + 2];
    }
    
    // Helper function to get the sum range from the segment tree
    int rangeSumQuery(int qlow, int qhigh, int low, int high, int pos) {
        if (qlow <= low && qhigh >= high) {
            return segTree[pos];
        }
        if (qlow > high || qhigh < low) {
            return 0;
        }
        int mid = (low + high) / 2;
        return rangeSumQuery(qlow, qhigh, low, mid, 2 * pos + 1) +
               rangeSumQuery(qlow, qhigh, mid + 1, high, 2 * pos + 2);
    }
    
public:
    NumArray(vector<int>& nums) {
        //this->nums = nums;
        n = nums.size();
        int x = (int)(ceil(log2(n)));
        int max_size = 2 * (int)pow(2, x) - 1;
        segTree.resize(max_size, 0);
        constructSegmentTree(segTree, nums, 0, n - 1, 0);
    }
    
    void update(int index, int val) {
        updateSegmentTree(index, val, 0, n - 1, 0);
    }
    
    int sumRange(int left, int right) {
        return rangeSumQuery(left, right, 0, n - 1, 0);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */