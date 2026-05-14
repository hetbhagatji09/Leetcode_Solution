class Solution {
public:
    void f(int i,vector<int>&nums,vector<int>&temp,vector<vector<int>>&ans){
        if(i == nums.size()){
            ans.push_back(temp);
            return;
        }
        
        if(i>=0){
            temp.push_back(nums[i]);
            f(i+1,nums,temp,ans);
            
            temp.pop_back();
        }
        f(i+1,nums,temp,ans);
    }
    vector<vector<int>> subsets(vector<int>& nums) {

        int n=nums.size();
        vector<vector<int>>ans;
        vector<int>temp;
        f(0,nums,temp,ans);
        return ans;
        // int n=nums.size();
        // vector<vector<int>>ans;
        // int totalSubsets=1<<n;
        // for(int num=0;num<totalSubsets;num++){
        //     vector<int>list;
        //     for(int i=0;i<n;i++){

        //         if(num & (1<<i)){
        //             list.push_back(nums[i]);
        //         }
        //     }
        //     ans.push_back(list);
        // }
        // return ans;
    }
};