class Solution {
public:
    bool isIsomorphic(string s, string t) {
        unordered_map<char,int>stMap;
        unordered_map<char,int>tsMap;
        int n=s.size();
        for(int i=0;i<n;i++){
            
            if((stMap.find(s[i])!=stMap.end()) && (stMap[s[i]]!=t[i]) || 
                (tsMap.find(t[i])!=tsMap.end()) && (tsMap[t[i]]!=s[i])){
                return false;
            }
            stMap[s[i]]=t[i];
            tsMap[t[i]]=s[i];
        }
        return true;


        
    }
};