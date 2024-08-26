class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        int i = 0, j = n - 1;
        while (i <= j) {
            int mid = (i + j) / 2;
            cout << i << " " << mid << " " << j << ";";
            if (nums[mid] == target) {
                return mid;
            }
            if (nums[i] <= nums[mid]) {
                if (nums[i] <= target && target <= nums[mid]) {
                    cout<<"one ";
                    j = mid - 1;
                } else {
                    cout<<"two ";
                    i = mid + 1;
                }

            } else {
                if (nums[mid] <= target && target <= nums[j]) {
                    cout<<"three ";
                    i = mid + 1;
                } else {
                    cout<<"four ";
                    j = mid - 1;
                }
            }
        }
        return -1;
    }
};