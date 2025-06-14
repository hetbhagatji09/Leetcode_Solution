class Solution {
public:
    int f(int i,int amount,vector<int>&coins,vector<vector<int>>&dp){
        if(i==0){
            if(amount % coins[i]==0){
                return amount/coins[i];
            }
            else return 1e9;
        }
        if(dp[i][amount]!=-1) return dp[i][amount];
        int take=INT_MAX;
        if(coins[i]<=amount) take=1+f(i,amount-coins[i],coins,dp);
        int non_take=f(i-1,amount,coins,dp);
        return dp[i][amount]=min(take,non_take);
    }
    int coinChange(vector<int>& coins, int amount) {
        int n=coins.size();
        vector<vector<int>>dp(n,vector<int>(amount+1,0));
        for(int target=0;target<=amount;target++){
            if(target % coins[0] == 0) dp[0][target]=(target/coins[0]);
            else dp[0][target]=1e9;
        }
        for(int i=1;i<n;i++){
            for(int t=0;t<=amount;t++){
                int not_take=0 + dp[i-1][t];
                int take=1e9;
                if(coins[i]<=t) take=1 + dp[i][t-coins[i]];
                dp[i][t]=min(take,not_take);
            }
        }
        if(dp[n-1][amount] >= 1e9) return -1;
        return dp[n-1][amount];
        // int ans=f(n-1,amount,coins,dp);
        // if(ans >=1e9) return -1;
        // return ans; 
    }
};