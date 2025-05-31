class Solution {
public:
    void generate(int n,int open,int close,string current,vector<string>&ans){
        if(n*2 ==current.size()){
            ans.push_back(current);
            return;
        }
        if(open<n)
        generate(n,open+1,close,current+'(',ans);
        if(close<open)
        generate(n,open,close+1,current+')',ans);
    }
    vector<string> generateParenthesis(int n) {
        vector<string>ans;
        string current="";
        generate(n,0,0,current,ans);
        return ans;

    }
};