class Solution {
public:
    string longestPalindrome(string s) {
        int n=s.size();
        int maxLen=0;
        string ans="";
        for(int i=0;i<n;i++){
            //odd length
            int l=i,r=i;
            while(l>=0 && r<n && s[l]==s[r]){
                if(r-l+1 > maxLen){
                    maxLen=r-l+1;
                    ans=s.substr(l,r-l+1);
                }
                l-=1;
                r+=1;
            }
            //even length
            l=i,r=i+1;
            while(l>=0 && r<n && s[l]==s[r]){
                if(r-l+1 > maxLen){
                    maxLen=r-l+1;
                    ans=s.substr(l,r-l+1);
                }
                l-=1;
                r+=1;
            }
        }
        return ans;
    }
};