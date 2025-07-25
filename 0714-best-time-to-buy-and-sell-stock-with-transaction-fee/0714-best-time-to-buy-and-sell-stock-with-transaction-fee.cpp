class Solution {
public:
int f(int ind,int buy,vector<int>&prices,vector<vector<int>>&dp,int fee){
        int profit=0;
        if(ind>=prices.size()) return 0;
        if(dp[ind][buy]!=-1) return dp[ind][buy];
        if(buy){
            profit=max(
                -prices[ind] + f(ind+1,0,prices,dp,fee),
                0 + f(ind+1,1,prices,dp,fee)
            );
        }
        else{
            profit=max(
                    prices[ind]-fee + f(ind+1,1,prices,dp,fee),
                    0   + f(ind+1,0,prices,dp,fee)   
            );
        }
        return dp[ind][buy]=profit;   
    }
    int maxProfit(vector<int>& prices, int fee) {
        int n=prices.size();
        vector<vector<int>>dp(n+1,vector<int>(2,-1));
        return f(0,1,prices,dp,fee);
        
    }
};