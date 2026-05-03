class Solution {
public:
    bool rotateString(string s, string goal) {
        for(int i = 0; i< s.size(); i++){
            string temp = "";
            for(int j = i; j < i + s.size(); j++){
                temp += s[j % s.size()];
            }
            if(temp == goal) return true;
        }
        return false;
    }
};