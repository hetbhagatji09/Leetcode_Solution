class Solution {
public:
    int climbStairs(int n) {
        //space complexity O(1)
        //time complexity O(n)
        int prev2=0;
        int prev=1;
        for(int i=0;i<n;i++){
            int current=prev2+prev;
            prev2=prev;
            prev=current;
        }
        return prev;
    }
};