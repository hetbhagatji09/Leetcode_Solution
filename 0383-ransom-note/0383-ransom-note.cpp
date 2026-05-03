class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        unordered_map<char,int>umap;
        for(int i=0;i<ransomNote.size();i++){
            umap[ransomNote[i]]++;
        }
        for(int i=0;i<magazine.size();i++){
            if(umap.find(magazine[i])!=umap.end()){
                umap[magazine[i]]--;
            }
            if(umap[magazine[i]]==0){
                umap.erase(magazine[i]);
            }
        }
        for (auto it = umap.begin(); it != umap.end(); ++it) {
            if (it->second !=0) return false;
        }
        return true;

    }
};