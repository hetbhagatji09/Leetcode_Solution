class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        int n=nums.size();
        vector<int>left,right,pivott;
        for(int i=0;i<n;i++){
            if(nums[i]<pivot){
                left.push_back(nums[i]);
            }
        }
        for(int i=0;i<n;i++){
            if(nums[i]>pivot){
                right.push_back(nums[i]);
            }
        }
        for(int i=0;i<n;i++){
            if(nums[i]==pivot)
            pivott.push_back(pivot);
        }
        left.insert(left.end(),pivott.begin(),pivott.end());
        left.insert(left.end(),right.begin(),right.end());
        return left;

    }
};