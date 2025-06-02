class Solution {
public:
void findAllPermutations(int index,vector<int>&nums,vector<int>&list,vector<bool>&used,vector<vector<int>>&ans){
        if(index==nums.size()){
            if(!list.empty()){
                ans.push_back(list);
            }
            return ;
        }
        for(int i=0;i<nums.size();i++){
            if(!used[i]){
                used[i]=true;
                list.push_back(nums[i]);
                findAllPermutations(index+1,nums,list,used,ans);
                list.pop_back();
                used[i]=false;
            }
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>>ans;
        vector<int>list;
        vector<bool> used(nums.size(),false);
        findAllPermutations(0,nums,list,used,ans);
        return ans;
    }
};