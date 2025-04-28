class Solution {
public:
    int sumOddLengthSubarrays(vector<int>& arr) {
        int n=arr.size();
        vector<int>prefixSum(n,0);
        int sum=0;
        prefixSum[0]=arr[0];
        for(int i=1;i<n;i++){
            prefixSum[i]=prefixSum[i-1]+arr[i];
        }
        for(int i=0;i<n;i++){
            for(int j=i;j<n;j++){
                int length=(j-i)+1;
               
                if(length % 2==1){
                    if(i==0){
                        sum+=prefixSum[j];
                    }
                    else sum += prefixSum[j]-prefixSum[i-1];
                }
            }
        }
        return sum;
      
    }
};