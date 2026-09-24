class Solution {
public:
    struct Item {
        int index;
        int temperature;
    };
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
        stack<Item> stk;
        vector<int> res(n, 0);
        for(int i = 0; i< n;i++) {
            int temp = temperatures[i];
            Item item{i, temp};
            while(!stk.empty()) {
                Item item = stk.top();
                if(item.temperature < temp) {
                    stk.pop();
                    res[item.index] = i - item.index;
                } else {
                    break;
                } 
            }
            stk.push(item);
        }
        return res;
    }
};
