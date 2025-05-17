class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char,int> umap;
        for(char c:s){
            umap[c]++;
        }
        priority_queue<pair<int,char>>q;
        for(auto it:umap){
            q.push({it.second,it.first});
        }
        string ans="";
        while(!q.empty()){
            pair<int,char> topp=q.top();
            q.pop();
            int count=topp.first;
            
            ans+= string(topp.first,topp.second);
        }
        return ans;


    }
};