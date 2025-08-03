class Solution {
public:
    int romanToInt(string s) {
        unordered_map<char,int>umap;
        umap['I']=1;
        umap['V']=5;
        umap['X']=10;
        umap['L']=50;
        umap['C']=100;
        umap['D']=500;
        umap['M']=1000;
        int ans=0;
        if(s.size()==1){
            return umap[s[0]];
        }
        for(int i=0;i<s.size();i++){
            if(umap[s[i]]<umap[s[i+1]]){
                ans+=(umap[s[i+1]]-umap[s[i]]);
                i++;
            }
            else{
                ans+=umap[s[i]];
            }
        }
        return ans;

    }
};