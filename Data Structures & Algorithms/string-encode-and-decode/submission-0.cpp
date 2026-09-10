class Solution {
public:

    string encode(vector<string>& strs) {
        char speparator = '/';
        vector<string> sizes;
        for(string s : strs) {
            sizes.push_back(to_string(s.size()));
        }
        string res = "";
        for(int i = 0;i < strs.size();i++) {
            res = res + sizes[i] + "/" + strs[i];
        }
        return res;
    }

    vector<string> decode(string s) {
        int n = s.size();
        int idx = 0;
        int size = 0;
        vector<string> res;
        while(idx < n) {
            if(s[idx] == '/') {
                string sub_str = s.substr(idx+1, size);
                res.push_back(sub_str);
                idx = idx + 1 + size;
                size = 0;
            } else {
                size = size * 10 + int(s[idx] - '0');
                idx += 1;
            }
        }
        return res;
    }
};
