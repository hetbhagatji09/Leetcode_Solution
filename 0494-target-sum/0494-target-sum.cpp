class Solution {
public:
    
    int f(int ind,vector<int> &arr,int target,vector<vector<int>> &dp){
        
         if (ind == 0) {
            if (target == 0 && arr[0] == 0) return 2; // {} and {0}
            if (target == 0 || target == arr[0]) return 1;
            return 0;
        }
        if(dp[ind][target]!=-1) return dp[ind][target];
        int not_pick=f(ind-1,arr,target,dp);
        int pick=0;
        
        if(arr[ind]<=target){
            pick=f(ind-1,arr,target-arr[ind],dp);
        }
        return dp[ind][target]=pick+not_pick;
    }
    int countPartitions(vector<int>& arr, int d) {
        int totalSum=0;
        int n=arr.size();
        for(int i:arr)totalSum+=i;
        if(totalSum-d <0 || (totalSum-d)%2==1) return 0;
        int target=(totalSum-d)/2;
        vector<vector<int>>dp(n,vector<int>(target+1,-1));
        return f(n-1,arr,target,dp);
        
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        return countPartitions(nums,target);
    }
};