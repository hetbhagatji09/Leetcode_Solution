class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int n=nums.size();
        int maxx=0;
        int ct=0;
        for(int i=0;i<n;i++){
            if(nums[i]!=0){
                ct++;
            }
            else{
                
                maxx=max(maxx,ct);
                ct=0;
            }
        }
        return max(ct,maxx);
    }
};