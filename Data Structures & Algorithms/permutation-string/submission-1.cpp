class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int n1 = s1.size();
        int n2 = s2.size();

        if(n1 > n2) return false;
        vector<int> freq_1(26, 0);
        for(int i = 0; i < n1;i++) {
            freq_1[s1[i] - 'a'] += 1;
        }
        for(int i = 0;i < n2-n1+1;i++) {
            int j = i + n1-1;
            vector<int> freq_2(26, 0);
            for(int k = i; k <= j;k++) {
                freq_2[s2[k]-'a'] += 1;
            }
            bool match = true;
            for(int h = 0;h < 26;h++) {
                if(freq_1[h] != freq_2[h]) {
                    match = false;
                    break;
                }
            }
            if(match) return true;
        }
        return false;
    }
};
