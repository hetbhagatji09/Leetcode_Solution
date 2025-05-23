class Solution {
public:
    bool isValid(string s) {
        stack<int>st;

        for(char c:s){
            if(!st.empty() && st.top()=='(' && c==')') st.pop();
            else if(!st.empty() && st.top()=='[' && c==']') st.pop();
            else if(!st.empty() && st.top()=='{' && c=='}') st.pop();
            else st.push(c);
        }
        if(!st.empty()){
            return false;
        }
        return true;  
    }
};