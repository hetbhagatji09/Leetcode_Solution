class Solution {
public:
    bool isPalindrome(string word){
        int i=0;
        int j=word.size()-1;
        while(i<j){
            if(word[i]!=word[j])return false;
            i++;
            j--;
        }
        return true;
    }
    string firstPalindrome(vector<string>& words) {
        for(string word:words){
            bool a=isPalindrome(word);
            if(a) return word;
           
        }
        return "";
    }
};