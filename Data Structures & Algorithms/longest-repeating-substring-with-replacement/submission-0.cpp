class Solution {
public:
    int characterReplacement(string s, int k) {
        int n = s.size();
        if(n <= k) return n;
        unordered_map<char, int> hash_map;
        int curr_dis_char = 1;
        int left = 0;
        hash_map[s[left]] = 1;
        int res = 1;
        int max_freq = 1;
        for(int right = 1; right < n;right++) {
            char c = s[right];
            if(hash_map.contains(c)) hash_map[c] += 1;
            else hash_map[c] = 1;

            max_freq = max(max_freq, hash_map[c]);

            while(right - left + 1 > max_freq + k) {
                char d = s[left];
                hash_map[d] -= 1;
                left ++;
            }
            res = max(res, right - left + 1);
        }
        return res;
    }
};
