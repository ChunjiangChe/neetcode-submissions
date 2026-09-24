class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        int n = position.size();
        stack<double> stk;
        vector<int> idx(n, 0)                                                                ;
        for(int i = 0;i < n;i++) idx[i] = i;

        sort(
            idx.begin(), idx.end(), 
            [&position](int a, int b) {return position[a] > position[b];}
        );

        for(int i = 0;i < n;i++) {
            int index = idx[i];
            int pos = position[index];
            int spd = speed[index];
            double time = (double)(target - pos) / spd;
            if(stk.empty()) {
                stk.push(time);
            } else {
                double front_time = stk.top();
                if(time > front_time) stk.push(time);
            }
        }
        return stk.size();

    }
};
