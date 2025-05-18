class Solution {
public:
    bool isPalindrome(string s) {
        int i=0;
        int n=s.size();
        int j=n-1;
        while(i<j){
            while(i<j && (isspace(s[i]) || !isalnum(s[i]))) i++;
            while(i<j && (isspace(s[j]) || !isalnum(s[j]))) j--;
            if(tolower(s[i])!=tolower(s[j])) return false;
            i++;
            j--;
        }
        return true;
    }
};