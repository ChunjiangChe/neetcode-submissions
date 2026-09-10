class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int, int> m;
        for(int i = 0;i < n;i++) {
            m[nums[i]] += 1;
        }
        vector<vector<int>> freq(n+1, vector<int>());
        for(const auto& pair : m) {
            if(pair.second > 0) {
                freq[pair.second].push_back(pair.first);
            }
        }
        vector<int> res;
        for(int i = freq.size()-1;i >= 1; i--){
            for(int val : freq[i]) {
                res.push_back(val);
                k--;
                if(k <= 0) return res;
            }
        }
        return res;
    }
};
