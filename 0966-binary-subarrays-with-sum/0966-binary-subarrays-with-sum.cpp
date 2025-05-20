class Solution {
public:
    int atMost(vector<int> &nums,int goal){
        int l=0;
        int r=0;
        int n=nums.size();
        int sum=0;
        int ct=0;
        if(goal<0) return 0;
        while(r<n){
            sum+=nums[r];
            while(sum>goal){
                sum-=nums[l];
                l++;
            }
            ct=ct+(r-l+1);
            r++;

        }
        return ct;
    }
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        
        return atMost(nums,goal)-atMost(nums,goal-1);
    }
};