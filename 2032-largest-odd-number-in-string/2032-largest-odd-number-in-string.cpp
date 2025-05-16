class Solution {
public:
    string largestOddNumber(string num) {
        int n=num.size();
        // int i=0;
        // int left=0;
        int j=n-1;
        // int right=0;
        // if((num[j]-'0')%2==1){
        //     return num;
        // }
        while(j>=0){
            if((num[j]-'0')%2==1){
                break;
            }
            j--;
        }
        int i;
        for(i=0;i<n;i++){
            if(num[i]!=0){
                break;
            }
        }
        if(j<=-1){
            return "";
        }
        return num.substr(i,j+1);
    }
};