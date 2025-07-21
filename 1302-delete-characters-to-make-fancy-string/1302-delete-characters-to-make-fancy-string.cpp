class Solution {
public:
    string makeFancyString(string s) {
        string ans="";
        int ct=1;
        char back;
        int n=s.size();
        for(int i=0;i<n;i++){
            if(back==s[i]) ct++;
            else ct=1;
            if(ct<3){
                ans+=s[i];
            }
            back=s[i];
            
        }
        return ans;
        
    }
};