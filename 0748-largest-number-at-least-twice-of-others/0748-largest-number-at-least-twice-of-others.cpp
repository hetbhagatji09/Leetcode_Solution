class Solution {
public:
    int dominantIndex(vector<int>& nums) {
     
        int n=nums.size();
        int num=-1;
        int index=0;
        int big=INT_MIN;
        for(int i=0;i<n;i++){
            if(big<nums[i]){
                big=nums[i];
                index=i;
            }
        }
        for(int i=0;i<n;i++){
            if(nums[i]*2 > big && index!=i){
                return -1;
            }
        }
        return index;
    }
};