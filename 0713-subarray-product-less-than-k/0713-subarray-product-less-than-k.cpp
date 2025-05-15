class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int ct=0;
        int n=nums.size();
        if(k<=1) return 0;
        int l=0;
        int product=1;
        for(int r=0;r<n;r++){
            product*=nums[r];
            while(product>=k){
                product=product/nums[l];
                l++;
            }
            ct+=(r-l+1);

        }
        return ct;
    }
};