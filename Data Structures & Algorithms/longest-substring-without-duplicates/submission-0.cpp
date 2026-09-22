class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        if(n <= 1) return n;
        unordered_map<char, bool> hash_map;
        int left = 0;
        hash_map[s[left]] = true;
        int res = 1;
        for(int right = 1; right < n;right ++) {
            char c = s[right];
            if(hash_map.contains(c) && hash_map[c] == true) {
                while(hash_map[c] == true) {
                    char d = s[left++];
                    hash_map[d] = false;
                }
            } 
            hash_map[c] = true;
            res = max(right - left + 1, res);
        }
        return res;
    }
};
