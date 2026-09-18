class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int n = numbers.size();
        int left = 0;
        int right = n-1;

        while(numbers[left] + numbers[right] != target) {
            if(numbers[left] + numbers[right] > target) right --;
            else left++;
        }
        
        vector<int> res;
        res.push_back(left + 1);
        res.push_back(right + 1);
        return res;
    }
};
