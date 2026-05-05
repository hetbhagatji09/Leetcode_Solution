class Solution {
public:
    int maxDistinct(string s) {
        unordered_map<char,int>umap;
        for(int i=0;i<s.size();i++){
            umap[s[i]]++;
        }
        return umap.size();
    }
};