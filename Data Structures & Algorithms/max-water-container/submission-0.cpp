class Solution {
public:
    int maxArea(vector<int>& heights) {
        int n = heights.size();        
        int left = 0;
        int right = n-1;
        int max_amount = 0;
        while(left < right) {
            max_amount = max(max_amount, min(heights[left], heights[right]) * (right - left));
            if(heights[left] < heights[right]) left++;
            else right--;
        }
        return max_amount;
    }
};
