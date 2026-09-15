class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, bool> hash_map;
        for(int i = 0; i < n;i++) {
            hash_map[nums[i]] = true;
        }

        int max_len = 0;
        for(int i = 0;i < n;i++) {
            int val = nums[i];
            if(hash_map.contains(val-1)) continue;
            int len = 1;
            while(true) {
                if(hash_map.contains(++val)) len += 1;
                else break;
            }
            max_len = max(len, max_len);
        }
        return max_len;
    }
};
