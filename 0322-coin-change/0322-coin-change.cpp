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
        vector<int>prev(amount+1,0),curr(amount+1,0);
        for(int target=0;target<=amount;target++){
            if(target % coins[0] == 0) prev[target]=(target/coins[0]);
            else prev[target]=1e9;
        }
        for(int i=1;i<n;i++){
            for(int t=0;t<=amount;t++){
                int not_take=0 + prev[t];
                int take=1e9;
                if(coins[i]<=t) take=1 + curr[t-coins[i]];
                curr[t]=min(take,not_take);
            }
            prev=curr;
        }
        if(prev[amount] >= 1e9) return -1;
        return prev[amount];
        // int ans=f(n-1,amount,coins,dp);
        // if(ans >=1e9) return -1;
        // return ans; 
    }
};