class Solution {
public:
    int f(int i,int amount,vector<int>&coins,vector<vector<int>>&dp){
        if(i==0){
            return (amount % coins[0] ==0) ? 1 :0;
        }
        if(dp[i][amount]!=-1) return dp[i][amount];
        int take=0;
        if(coins[i]<=amount) take=f(i,amount-coins[i],coins,dp);
        int non_take=f(i-1,amount,coins,dp);
        return dp[i][amount]=take+non_take;
    }
    int change(int amount, vector<int>& coins) {
        int n=coins.size();
        vector<vector<int>>dp(n,vector<int>(amount+1,-1));
        return f(n-1,amount,coins,dp);
    }
};