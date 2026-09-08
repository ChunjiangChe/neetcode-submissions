class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char, int> m;
        for(char c : s) {
            if(!m.contains(c)) {
                m[c] = 1;
            } else {
                m[c] += 1;
            }
        }
        for(char c : t) {
            if(!m.contains(c)) {
                m[c] = -1;        
            } else {
                m[c] -= 1;
            }
        }
        for(auto& [key, value]: m) {
            if(value != 0) return false;
        }
        return true;
    }
};
