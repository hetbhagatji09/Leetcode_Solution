class Solution {
public:
    int f(int ind,vector<int>&nums,vector<int>&dp){
        int n=nums.size();
        if(ind >= n-1) return 0;
        if(dp[ind]!=-1) return dp[ind];
        int minJumps=INT_MAX;
        for(int i=1;i<=nums[ind];i++){
          
            int jump=f(ind+i,nums,dp);
            if(jump!=INT_MAX)
            minJumps=min(minJumps,jump+1);
        }
        return dp[ind]=minJumps;
    }
    int jump(vector<int>& nums) {
        int n=nums.size();
        if(n<=1) return 0;
        vector<int>dp(n+1,-1);
        return f(0,nums,dp);
    }
};