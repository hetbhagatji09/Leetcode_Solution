class Solution {
public:
    int f(int ind,int buy,vector<int>&prices,vector<vector<vector<int>>>&dp,int capacity){
        int profit=0;
        if(ind==prices.size()) return 0;
        if(capacity==0) return 0;
        if(dp[ind][buy][capacity]!=-1) return dp[ind][buy][capacity];
        if(buy){
            profit=max(
                -prices[ind] + f(ind+1,0,prices,dp,capacity),
                0 + f(ind+1,1,prices,dp,capacity)
            );
        }
        else{
            profit=max(
                    prices[ind] + f(ind+1,1,prices,dp,capacity-1),
                    0   + f(ind+1,0,prices,dp,capacity)   
            );
        }
        return dp[ind][buy][capacity]=profit;   
    }
    int maxProfit(int k, vector<int>& prices) {
        int n=prices.size();
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(2, vector<int>(k+1, -1)));
        return f(0,1,prices,dp,k);   
    }
};