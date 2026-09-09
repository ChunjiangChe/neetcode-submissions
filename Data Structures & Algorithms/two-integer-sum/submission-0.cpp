class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();
        unordered_map<int, int> m;
        for(int i = 0;i < n;i++) {
            int val = nums[i];
            if(m.contains(val)) {
                vector<int> res;
                res.push_back(m[val]);
                res.push_back(i);
                return res;
            }
            int difference = target - val;
            m[difference] = i;
        }
        return vector<int>();
    }
};
