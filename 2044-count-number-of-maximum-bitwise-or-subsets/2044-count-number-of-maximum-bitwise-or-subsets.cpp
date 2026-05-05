class Solution {
public:
    int countMaxOrSubsets(vector<int>& nums) {
        int n = nums.size();
        int ct=0;
        int maxOr=0;
        for(int i=0;i<n;i++){
            maxOr =maxOr | nums[i];
        }

        for(int mask =0;mask < (1<<n);mask++){
            int currOr = 0;
            for(int i=0;i<n;i++){
                if( mask & (1<<i)){
                    currOr |= nums[i];
                }
            }
            if (currOr == maxOr) ct++;
        }
        return ct;
    }
};