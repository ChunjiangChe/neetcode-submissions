class Solution {
public:
    bool isValid(string s) {
        int n = s.size();
        stack<char> stk;
        for(int i = 0;i < n;i++) {
            char c = s[i];
            if(stk.empty()) stk.push(c);
            else {
                char top = stk.top();
                if(top == '(' && c == ')') stk.pop();
                else if (top == '[' && c == ']') stk.pop();
                else if (top == '{' && c == '}') stk.pop();
                else stk.push(c);
            }
        }
        return stk.empty();
    }
};
