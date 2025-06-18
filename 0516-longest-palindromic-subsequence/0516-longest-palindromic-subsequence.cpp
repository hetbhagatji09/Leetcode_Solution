class Solution {
public:
    int f(string s1,string s2,int i1,int i2, vector<vector<int>>&dp){
        if(i1 == 0 || i2 == 0) return 0;
        if(dp[i1][i2]!=-1) return dp[i1][i2];
        if(s1[i1-1] == s2[i2-1]) return 1 + f(s1,s2,i1-1,i2-1,dp);
        return dp[i1][i2]=max(f(s1,s2,i1-1,i2,dp),f(s1,s2,i1,i2-1,dp));
    } 

    int longestPalindromeSubseq(string s1) {
        string orignal=s1;
        reverse(s1.begin(),s1.end());
        int m=s1.size();
        
        vector<vector<int>>dp(m+1,vector<int>(m+1,0));
        // for(int i=0;i<=m;i++){
        //     dp[i][0]=0;
        //     dp[0][i]=0;
        // }
        for(int i=1;i<=m;i++){
            for(int j=1;j<=m;j++){
                if(s1[i-1]==orignal[j-1]){
                    dp[i][j]= 1 +dp[i-1][j-1];
                }
                else{
                    dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
                }
            }
        }
        // return f(s1,orignal,m,m,dp);
        return dp[m][m];    
    }
};