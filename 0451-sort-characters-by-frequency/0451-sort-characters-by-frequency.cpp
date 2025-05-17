class Solution {
public:
    string frequencySort(string s) {
        priority_queue<pair<int,char>>q;
        sort(s.begin(),s.end());
        unordered_map<char,int>umap;
        string ans="";
        for(char x:s){
            umap[x]++; 
        }
        for(auto x:umap)
        {
            q.push({x.second,x.first});
        }
        while(!q.empty()){
            int ct=q.top().first;
            while(ct--){
                ans+=q.top().second;
            }
            q.pop();
        }
        return ans;
        
        
    }
};