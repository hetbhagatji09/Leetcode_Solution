class Solution {
public:
    void findCombinations(int index,vector<int>&list,int n,int k,vector<vector<int>>&ans){
        if(k==list.size()){ 
            if(!list.empty()){
                ans.push_back(list);
            }
            return ;
        }
        for(int i=index;i<=n;i++){
            list.push_back(i);
            findCombinations(i+1,list,n,k,ans);
            list.pop_back();
        }

    }
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>>ans;
        vector<int>list;
        findCombinations(1,list,n,k,ans);
        return ans;
    }

};