class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int size=s1.size();
        sort(s1.begin(),s1.end());
        for(int j=0;j<s2.size();j++){
            string hey= s2.substr(j,size);
            sort(hey.begin(),hey.end());
            if(hey == s1) return true;
        }
        return false;
    }
};