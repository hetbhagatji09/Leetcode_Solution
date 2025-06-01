class Solution {
public:
    void findCombinations(int index,string &digits,string current,vector<string>&ans,unordered_map<char,string>&umap){
        if( index == digits.size() ){
            if(!current.empty()){
                ans.push_back(current);
            }
            return;
        }
        char ch=digits[index];
        string hey=umap[ch];
        for(char c:hey){
            current.push_back(c);
            findCombinations(index+1,digits,current,ans,umap);
            current.pop_back();
        }
    }
    vector<string> letterCombinations(string digits) {
        vector<string>ans;
        unordered_map<char,string>umap={
            {'2',"abc"},
            {'3',"def"},
            {'4',"ghi"},
            {'5',"jkl"},
            {'6',"mno"},
            {'7',"pqrs"},
            {'8',"tuv"},
            {'9',"wxyz"}
        };
        findCombinations(0,digits,"",ans,umap);
        return ans;
    }
};