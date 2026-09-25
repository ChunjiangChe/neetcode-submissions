class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        int i = 0;
        int j = n;
        while(i < j) {
            int mid = (i + j) / 2;
            if(nums[mid] == target) return mid;
            else if (nums[mid] > target) {
                j = mid;
            } else {
                i = mid + 1;
            }
        }
        return -1;
    }
};
