class Solution {
public:
    int divide(int dividend, int divisor) {
        if (dividend == INT_MIN && divisor == -1)
            return INT_MAX;
        if(dividend==divisor) return 1;
        bool sign=true;
        if(dividend>0 && divisor<=0) sign=false;
        if(dividend<0 && divisor>=0) sign=false;
        long n=abs(long(dividend));
        long ans=0;
        long d=abs(long(divisor));
        while(n>=d){
            int ct=0;
            while(n>= (d << (ct+1))){
                ct++;
            }
            
            ans+=(1<<ct);
            n=n-( d << ct);

        }
        
        

        return sign?ans:ans*-1;
    }
};