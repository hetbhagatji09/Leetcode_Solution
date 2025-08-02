class Solution {
public:
    void findAllPermutations(int index,vector<int>&nums,vector<int>&list,vector<bool>&used,vector<vector<int>>&ans){
        if(list.size()==nums.size()){
            if(!list.empty()){
                ans.push_back(list);
                return ;
            }
            
        }
        for(int i=0;i<nums.size();i++){
            if(!used[i]){
                list.push_back(nums[i]);
                used[i]=true;
                findAllPermutations(i,nums,list,used,ans);
                list.pop_back();
                used[i]=false;
            }
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>>ans;
        int n=nums.size();
        vector<int>list;
        vector<bool>used(n,false);
        findAllPermutations(0,nums,list,used,ans);
        set<vector<int>>anss(ans.begin(),ans.end());
        vector<vector<int>>ansss(anss.begin(),anss.end());
        return ansss;
        
    }
};