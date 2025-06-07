class Solution {
public:
    int f(int ind,vector<int> &nums,vector<int>&dp){
        if(ind==0) return nums[0];
        if(ind<0) return 0;
        if(dp[ind]!=-1) return dp[ind];
        int pick=nums[ind]+f(ind-2,nums,dp);
        int notpick= 0+f(ind-1,nums,dp);
        return dp[ind]=max(notpick,pick);
    }
    int rob(vector<int>& nums) {
        int prev=nums[0];
        int prev2=0;
        for(int i=0;i<nums.size();i++){
            int take=nums[i];
            if(i>1) take+=prev2;
            int nottake=0 + prev;
            int current=max(take,nottake);
            prev2=prev;
            prev=current;
        }
        return prev;
    }
};