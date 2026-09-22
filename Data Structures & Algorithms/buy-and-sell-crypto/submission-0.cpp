class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        if(n <= 0) return 0;
        int min_buy = prices[0];
        vector<int> profits;
        for(int i = 0;i < n;i++) {
            min_buy = min(min_buy, prices[i]);
            profits.push_back(prices[i] - min_buy);
        }
        int res = 0;
        for(int i = 0;i < n;i++) {
            res = max(res, profits[i]);
        }
        return res;
    }
};
