class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char,int>umap;
        int l=0;
        int r=0;
        int maxLength=0;
        int n=s.size();
        while(r<n){
            if(umap.find(s[r])!=umap.end() && umap[s[r]]>=l){
                auto value=umap[s[r]];
                l=value+1;
                umap[s[r]]=r;
            }
            
                
                maxLength=max(maxLength,r-l+1);
                cout<<s.substr(l,r-l+1)<<" ";
                umap[s[r]]=r;
                
            
            r++;
            
        }
        return maxLength;
    }
};