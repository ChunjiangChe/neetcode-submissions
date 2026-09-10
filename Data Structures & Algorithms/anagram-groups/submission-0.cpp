class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        int n = strs.size();
        unordered_map<string, vector<string>> m;
        for(int i = 0;i < n;i++) {
            string s = strs[i];
            vector<int> v(26, 0);
            for(char c: s) {
                int idx = int(c - 'a');
                v[idx] += 1;
            }
            //convert the vector to string
            string tmp = "";
            for(char c : v) {
                tmp += c - '0';
            }
            m[tmp].push_back(s);
        }
        vector<vector<string>> res;
        for(const auto& pair : m) {
            res.push_back(pair.second);
        }
        return res;
    }
};
