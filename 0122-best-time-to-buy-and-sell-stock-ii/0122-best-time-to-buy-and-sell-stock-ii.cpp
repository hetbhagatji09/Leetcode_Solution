class Solution {
public:
    int f(int ind,int buy,vector<int>&prices,vector<vector<int>>&dp){
        int profit=0;
        if(ind>=prices.size()) return 0;
        if(dp[ind][buy]!=-1) return dp[ind][buy];
        if(buy){
            profit=max(
                -prices[ind] + f(ind+1,0,prices,dp),
                0 + f(ind+1,1,prices,dp)
            );
        }
        else{
            profit=max(
                    prices[ind] + f(ind+2,1,prices,dp),
                    0   + f(ind+1,0,prices,dp)   
            );
        }
        return dp[ind][buy]=profit;   
    }
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        // vector<vector<int>>dp(n+1,vector<int>(2,0));
        vector<int>ahead(2,0),curr(2,0);
        ahead[0]=0;
        ahead[1]=0;
        int profit=0;
        for(int i=n-1;i>=0;i--){
            for(int buy=0;buy<2;buy++){
                if(buy){
                    profit=max(
                        -prices[i] + ahead[0],
                        0 + ahead[1]
                    );
                }
                else{
                    profit=max(
                        prices[i] + ahead[1],
                        ahead[0]  
                    );
                }
                curr[buy]=profit;
            }
            ahead=curr;
        }
        return ahead[1];
        // return f(0,1,prices,dp);
    }
};