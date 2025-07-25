class Solution {
public:
    int f(int i,int j,vector<vector<int>>&dp){
        if(i==0 && j==0) return 1;
        if(i<0 || j<0) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        int left=f(i,j-1,dp);
        int up=f(i-1,j,dp);
        return dp[i][j]=left+up;
    }
    int uniquePaths(int m, int n) {
        vector<vector<int>>dp(m,vector<int>(n,-1));
        // return f(m-1,n-1,dp);
        
        for(int i=0;i<m;i++){
            int left=0,up=0;
            for(int j=0;j<n;j++){
                if(i==0 && j==0){
                    dp[0][0]=1;
                    continue;
                }
                else{
                    int left=0,right=0;
                    if(j>0)
                    left=dp[i][j-1];
                    if(i>0)
                    up=dp[i-1][j];
                    dp[i][j]=left+up;
                }
                
            }
        }
        return dp[m-1][n-1];
    }
};