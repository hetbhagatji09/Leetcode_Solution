class Solution {
public:
    int f(int i,int j,vector<vector<int>>&matrix,vector<vector<int>>&dp){
        
        if(i<0 || j<0 || i>=matrix.size() || j>= matrix.size()) return INT_MAX;
        if(i==0) return matrix[i][j];
        if(dp[i][j]!=-1) return dp[i][j];
        int up=f(i-1,j,matrix,dp);
        int leftDiagonal=f(i-1,j-1,matrix,dp);
        int rightDiagonal=f(i-1,j+1,matrix,dp);
        return dp[i][j]=matrix[i][j]+min(up,min(leftDiagonal,rightDiagonal));
    
    }
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n=matrix.size();
        int mini=INT_MAX;
        vector<vector<int>>dp(n,vector<int>(n,0));
        for(int j=0;j<n;j++){
            dp[n-1][j]=matrix[n-1][j];
        }
        for(int i=n-2;i>=0;i--){
            for(int j=0;j<n;j++){
               int down = dp[i + 1][j];
                int leftDiagonal = (j > 0) ? dp[i + 1][j - 1] : INT_MAX;
                int rightDiagonal = (j < n - 1) ? dp[i + 1][j + 1] : INT_MAX;

                dp[i][j] = matrix[i][j] + min({down, leftDiagonal, rightDiagonal});

            }
        }
        
        for(int i=0;i<n;i++){
            mini=min(mini,dp[0][i]);
        }

        return mini;
    }
};