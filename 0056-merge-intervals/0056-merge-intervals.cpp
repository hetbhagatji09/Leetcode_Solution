class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end());
        vector<vector<int>>ans;
        int m=intervals.size();
        ans.push_back(intervals[0]);

        for(int i=1;i<m;i++){
            if(ans.back()[1] >= intervals[i][0]){
                ans.back()[1]=max(intervals[i][1],ans.back()[1]);
            }
            else{
                ans.push_back(intervals[i]);
            }


        }
        return ans;
    }
};