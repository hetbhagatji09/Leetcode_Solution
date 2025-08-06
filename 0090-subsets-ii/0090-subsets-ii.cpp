class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>>ans;
        int n=nums.size();
        sort(nums.begin(),nums.end());
        int total=1<<n;
        for(int i=0;i<total;i++){
            vector<int>list;
            for(int j=0;j<n;j++){
                if(i & (1<<j)){
                    list.push_back(nums[j]);
                }
            }
            ans.push_back(list);
        }
        set<vector<int>>s(ans.begin(),ans.end());
        vector<vector<int>>anss(s.begin(),s.end());
        return anss;
    }
};