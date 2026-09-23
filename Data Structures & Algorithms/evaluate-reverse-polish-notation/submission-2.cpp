class Solution {
public:
    int str2int(string s) {
        int res = 0;
        int i = 0;
        bool negative = false;
        if(s[i] == '-') {
            i++;
            negative = true;
        }
        for(;i < s.size();i ++) {
            res = res * 10 + (s[i] - '0');
        }
        if(negative) res = -res;
        return res;
    }
    int evalRPN(vector<string>& tokens) {
        int n = tokens.size();
        stack<int> stk;
        for(int i = 0;i < n;i++) {
            string token = tokens[i];
            int s = token.size();
            if(isdigit(token[s-1])) {
                stk.push(str2int(token));
            } else if(token == "+") {
                int val2 = stk.top();
                stk.pop();
                int val1 = stk.top();
                stk.pop();
                stk.push(val1 + val2);
            } else if(token == "-") {
                int val2 = stk.top();
                stk.pop();
                int val1 = stk.top();
                stk.pop();
                stk.push(val1 - val2);
            } else if(token == "*") {
                int val2 = stk.top();
                stk.pop();
                int val1 = stk.top();
                stk.pop();
                stk.push(val1 * val2);
            } else if(token == "/") {
                int val2 = stk.top();
                stk.pop();
                int val1 = stk.top();
                stk.pop();
                stk.push(val1 / val2);
            }
        }
        return stk.top();
    }
};
