class Solution {
public:
    bool isSubsetSum(vector<int>& arr, int sum) {
        int n=arr.size();
        vector<vector<bool>>dp(n,vector<bool>(sum+1,false));
        for(int i=0;i<n;i++){
            dp[i][0]=true;
        }
        if(arr[0]<=sum) dp[0][arr[0]]=true;
        for(int i=1;i<n;i++){
            for(int s=1;s<=sum;s++){
                bool not_take=dp[i-1][s];
                bool take=false;
                if(arr[i]<=s) take=dp[i-1][s-arr[i]];
                dp[i][s]=take || not_take;
            }
        }
        return dp[n-1][sum];
        // return f(arr.size()-1,sum,arr,dp);
    }
    bool canPartition(vector<int>& nums) {
        int totalSum=0;
        for(int a:nums) totalSum+=a;
        if(totalSum%2==1) return false;
        return isSubsetSum(nums,(totalSum/2));

    }
};