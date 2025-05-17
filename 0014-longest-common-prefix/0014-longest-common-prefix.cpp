class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string prefix=strs[0];
        int prefixLen=0;
        for(int i=1;i<strs.size();i++){
            string word=strs[i];
            int j=0;
            while(j< word.size() && word[j]==prefix[j]){
                j++;
            }
            prefix=prefix.substr(0,j);
        }
        return prefix;
    }
};