class Solution {
public:
    int strStr(string haystack, string needle) {
        int n=needle.size();
        if(needle==haystack)return 0;
        for(int i=0;i<haystack.size();i++){
            if(needle==haystack.substr(i,n)){
                return i;
                break;
            }
        }
        return -1;
    }
};