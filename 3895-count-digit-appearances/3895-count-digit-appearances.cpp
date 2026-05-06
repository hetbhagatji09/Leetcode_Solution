class Solution {
public:
    int countDigitOccurrences(vector<int>& nums, int digit) {
        int ct=0;
        for(int i=0;i<nums.size();i++){
            while(nums[i]>0){
                int r= nums[i] %10;
                if(r==digit) ct++;
                nums[i] = nums[i] / 10;
            }
            
                
        }
        return ct;
    }
};