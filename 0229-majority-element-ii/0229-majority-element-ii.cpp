class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        unordered_map<int,int>umap;
        int n=nums.size();
        for(int i=0;i<n;i++){
            umap[nums[i]]++;
        }
        int ct=n/3;
        vector<int>ans;
        for(auto ele:umap){
            int key=ele.first;
            int value=ele.second;
            if(value>ct){
                ans.push_back(key);
            }
        }
        return ans;

    }
};