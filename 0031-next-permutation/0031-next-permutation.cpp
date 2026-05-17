class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n=nums.size();
        int pivot=-1;
        int i;
        for(i=n-2;i>=0;i--){
            if(nums[i+1] > nums[i]){
                pivot = i;
                break;
            }
        }
        if(pivot==-1){
            reverse(nums.begin(),nums.end());
            return;
        }
        for(i=n-1;i>pivot;i--){
            if(nums[pivot]< nums[i]){
                swap(nums[pivot],nums[i]);
                break;
            }
        }
        reverse(nums.begin()+pivot+1,nums.end());
    }
};