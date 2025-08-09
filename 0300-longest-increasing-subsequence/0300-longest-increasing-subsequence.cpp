class Solution {
public:
    int f(int index,vector<int>&nums,int prevIndex,vector<vector<int>>&dp){
        if(index<0) return 0;
        int take=INT_MIN;
        if(dp[index][prevIndex]!=-1) return dp[index][prevIndex];
        if(prevIndex==0 || nums[index]<nums[prevIndex]){
            take=1+f(index-1,nums,index,dp);
        }
        int not_take=0+f(index-1,nums,prevIndex,dp);
        return dp[index][prevIndex]=max(take,not_take);
    }
    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
        vector<vector<int>>dp(n,vector<int>(n,-1));
        return f(n-1,nums,0,dp);
    }
};