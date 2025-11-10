class Solution {
public:
    int sumOfSquare(int n){
        int total=0;
        while(n>0){
            int num=n%10;
            total+=num*num;
            n=n/10;
        }
        return total;
    }
    bool isHappy(int n) {
        unordered_set<int>seen;
        while(n!=1 && !seen.count(n)){
            seen.insert(n);
            n=sumOfSquare(n);
        }
        return n==1;
    }
};