class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string,vector<string>>umap;
        for(string s:strs){
            string temp=s;
            sort(s.begin(),s.end());
            umap[s].push_back(temp);
        }
        vector<vector<string>>ans;
        for(auto it:umap){
            ans.push_back(it.second);
        }
        return ans;
    }
};