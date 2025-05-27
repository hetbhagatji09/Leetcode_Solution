class Solution {
public:
    int findMin(vector<int>& nums) {
        int low=0;
        int high=nums.size()-1;
        int mini=INT_MAX;
        while(low<=high){
            int mid=(high+low)/2;
            if(nums[mid]<=nums[high]){
                mini=min(mini,nums[mid]);
                high=mid-1;
            }
            else{
                low=mid+1;
                mini=min(mini,nums[low]);
            } 
        }
        return mini;
        
    }
};