class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        long long maxSum=0;
        int l=0,r=0;
        unordered_map<int,int>umap;
        long long sum=0;
        int n=nums.size();
        while(r<n){
           
            sum+=nums[r];
            umap[nums[r]]++;
            
            while( (r-l+1 > k) || umap[nums[r]]>1){   
                umap[nums[l]]--;
                sum-=nums[l];
                l++;
            }
         
            if((r-l+1)==k) maxSum=max(maxSum,sum);
            
            cout<<maxSum<<" ";
            r++;
        }
        return maxSum;
    }
};