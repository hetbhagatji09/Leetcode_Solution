class Solution {
public:
    int numberOfSubstrings(string s) {
        unordered_map<int,int>umap;
        umap[0]=umap[1]=umap[2]=-1;

        int ct=0,n=s.size();
        for(int i=0;i<n;i++){
            umap[s[i]-'a']=i;
            if(umap[0]!=-1 && umap[1]!=-1 && umap[2]!=-1){
                ct+=1+min(umap[0],min(umap[1],umap[2]));
            }
        }
        return ct;
    }
};