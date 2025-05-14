class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n=nums.size(); 
        vector<int>leftSum(n,1);
        vector<int>rightSum(n,1);
        vector<int>ans(n,1);
        rightSum[0]=nums[0];
        if(n==0){
            return {};
        }
        if(n==1){
            return nums;
        }
        for(int i=1;i<n;i++){
            rightSum[i]=rightSum[i-1]*nums[i];
        }
        cout<<endl;
        leftSum[n-1]=nums[n-1];
        for(int i=n-2;i>=0;i--){
            leftSum[i]=nums[i]*leftSum[i+1];
        }
        ans[0]=leftSum[1];
        // cout<<"Left sum is"<<" "<<endl;
        // for(int i=0;i<n;i++){
        //     cout<<leftSum[i]<<" ";
        // }
        // cout<<endl;
        // cout<<"Right sum is"<<" "<<endl;
        //  for(int i=0;i<n;i++){
        //     cout<<rightSum[i]<<" ";
        // }
        // cout<<endl;
        ans[n-1]=rightSum[n-2];
        for(int i=1;i<n-1;i++){
            ans[i]=rightSum[i-1]*leftSum[i+1];
        }
        return ans;
        

    }
};