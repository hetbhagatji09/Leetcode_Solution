class Solution {
public:
    void findSubsequences(int index, vector<int>& arr, vector<int>& current, vector<vector<int>>& result) {
        if (index == arr.size() ) {
            if(current.size()>1)
            result.push_back(current);
            return;
        }

        if( current.empty() || current.back()<=arr[index]){
            current.push_back(arr[index]);
            findSubsequences(index + 1, arr, current, result);
            current.pop_back();
              
        }
        findSubsequences(index + 1, arr, current, result);
         
        
        
    }
    vector<vector<int>> findSubsequences(vector<int>& nums) {
       vector<vector<int>> result;
        vector<int> current;
        findSubsequences(0, nums, current, result);
        sort(result.begin(),result.end());
        set<vector<int>>res(result.begin(),result.end());
        return vector<vector<int>>(res.begin(),res.end());
    }
};