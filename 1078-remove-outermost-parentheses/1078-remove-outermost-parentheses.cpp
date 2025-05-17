class Solution {
public:
    string removeOuterParentheses(string s) {
        int ct=0;
        string ans="";
        for(char c:s){
            if(c == '('){
                if(ct>0){
                    ans+=c;
                }
                ct++;
            }
            else{
                ct--;
                if(ct>0) ans+=c;
            }
        }
        return ans;
    }
};