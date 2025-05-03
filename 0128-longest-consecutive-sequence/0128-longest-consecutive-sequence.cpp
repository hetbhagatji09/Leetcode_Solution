class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        set<int>s1(nums.begin(),nums.end());
        vector<int>hey(s1.begin(),s1.end());
        sort(hey.begin(),hey.end());
        int ct=1;
        int maxx=0;
        int n=hey.size();
        if(n==0) return 0;
        for(int i=1;i<n;i++){
            if(hey[i] == hey[i-1] +1) ct++;
            else{
                maxx=max(ct,maxx);
                ct=1;
            }

        }
        return max(ct,maxx);
    }
};