class Solution {
public:

    void findCombinations(
        int index,
        int target,
        vector<int>candidates,
        vector<vector<int>>&ans,
        vector<int>list){
            if(index==candidates.size()){
                if(target==0){
                    ans.push_back(list);
                }
                return;
            }
            if(candidates[index]<=target){
                list.push_back(candidates[index]);
                findCombinations(index,target-candidates[index],candidates,ans,list);
                list.pop_back();        
            }
            findCombinations(index+1,target,candidates,ans,list);
            
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int>list;
        vector<vector<int>>ans;
        findCombinations(0,target,candidates,ans,list);
        return ans;
    }
};