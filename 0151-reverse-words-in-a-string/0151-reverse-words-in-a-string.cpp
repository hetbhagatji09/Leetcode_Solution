class Solution {
public:
    string reverseWords(string s) {
        string ans;
        vector<string> words;
        int i=0;
        while(s[i]==' '){
            i++;
        }
        int n=s.size();
        s=s.substr(i);
        i=s.size()-1;
        while(i>=0 && s[i]==' '){
            i--;
        }
        s=s.substr(0,i+1);
        n=s.size();
        int j=0;
        for(int i=0;i<n;i++){
            string word="";
            while (i < n && s[i] == ' ') i++;
            while(i<n && !isspace(s[i]) ){
                word+=s[i];
                i++;
            }
            if(!word.empty()) words.push_back(word);
            
        }
        for(auto word:words){
            cout<<word<<" ";
        }
        for(int i=words.size()-1;i>=0;i--){
            ans+=words[i]+' ';
            
        }
        return ans.substr(0,ans.size()-1);
    }
};