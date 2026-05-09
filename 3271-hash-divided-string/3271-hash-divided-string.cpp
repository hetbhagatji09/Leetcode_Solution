class Solution {
public:
    string stringHash(string s, int k) {
        int n=s.size();
        int i=0;
        string ans="";
        while(i<n){
            int total=0;
            for(int j=i;j<i+k;j++){
                total+=(s[j]-'a');
            }
            ans+=(char)((total % 26) + 'a');
            i+=k;
        }
        return ans;
    }
};