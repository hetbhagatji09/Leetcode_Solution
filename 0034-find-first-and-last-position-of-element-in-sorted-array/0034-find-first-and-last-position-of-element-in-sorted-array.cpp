class Solution {
public:
    int firstPosition(vector<int>&nums,int target){
        int low=0;
        int ans=-1;
        int high=nums.size()-1;
        while(low<=high){
            int mid=(low+high)/2;
            if(nums[mid]==target){
                ans=mid;
                high=mid-1;
            }
            else if(nums[mid]<target)low=mid+1;
            else high=mid-1;
        }
        return ans;
    }
    int lastPosition(vector<int>&nums,int target){
        int low=0;
        int ans=-1;
        int high=nums.size()-1;
        while(low<=high){
            int mid=(low+high)/2;
            if(nums[mid]==target){
                ans=mid;
                low=mid+1;
            }
            else if(nums[mid]<target)low=mid+1;
            else high=mid-1;
        }
        return ans;
    }
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int>ans;
        int first=firstPosition(nums,target);
        int last=lastPosition(nums,target);
        ans.push_back(first);
        ans.push_back(last);
        return ans;
    }
};