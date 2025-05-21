class Solution {
public:
    int minBitFlips(int start, int goal) {
        int x=start ^ goal;
        int ct=0;
        while(x!=0){
            ct++;
            x = x & (x-1);

        }
        return ct;
    }
};