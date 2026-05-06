class Solution {
public:
    vector<string> validStrings(int n) {
        vector<string>ans;
        int total = pow(2, n);
        for (int i = 0; i < total; i++) {
            string s = "";
            for (int j = n - 1; j >= 0; j--) {
                if ((i >> j) & 1) s += '1';
                else s += '0';
            }
           if (s.find("00") == std::string::npos) {
            ans.push_back(s);
            }
           
        }
        return ans;
    }
};