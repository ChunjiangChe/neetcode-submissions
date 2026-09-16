class Solution {
public:
    bool isPalindrome(string s) {
        int n = s.size();
        int left = 0;
        int right = n-1;
        while(!isalnum(s[left])) left += 1;
        while(!isalnum(s[right])) right -= 1;
        while(left < right) {
            if(tolower(s[left]) != tolower(s[right])) {
                cout << "confict: " <<s[left] << " : " << s[right] << endl;
                return false;
            }
            left += 1;
            right -= 1;
            while(!isalnum(s[left])) left += 1;
            while(!isalnum(s[right])) right -= 1;
        }
        return true;
    }
};
