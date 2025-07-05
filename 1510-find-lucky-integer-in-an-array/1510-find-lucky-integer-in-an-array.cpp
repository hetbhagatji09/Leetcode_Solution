class Solution {
public:
    int findLucky(vector<int>& arr) {
        unordered_map<int,int>umap;
        for(int a:arr){
            umap[a]++;
        }
        int maxx=-1;
        for(auto it:umap){
            if(it.second==it.first){
                maxx=max(maxx,it.first);
            }
        }

        return maxx!=-1? maxx :-1;
    }
};