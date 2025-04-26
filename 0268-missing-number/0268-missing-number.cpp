class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        int total = n * (n + 1) / 2;  // sum of 0 to n
        int sum = 0;
        for (int num : nums) {
            sum += num;
        }
        return total - sum;
    }
};
