class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int l=0,r=0,maxLen=0,n=nums.size(),zeroCount=0;
        while(r<n){
            if(nums[r]==0) zeroCount++;
            while(zeroCount>k){

                if(nums[l]==0)zeroCount--;
                l++;
            }
            maxLen=max(maxLen,r-l+1);
            r++;
        }
        return maxLen;
    }
};