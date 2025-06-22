class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        vector<int>ans;
        int n=nums.size();
        stack<int>st;
        for(int i=n*2-1;i>=n;i--){
            int ind=i%n;
            while(!st.empty() && st.top()<=nums[ind]){
                st.pop();
            }
            st.push(nums[ind]);  
        }
        for(int i=n-1;i>=0;i--){
            while(!st.empty() && st.top()<=nums[i]){
                st.pop();
            }
            int anss=st.empty()?-1:st.top();
            ans.push_back(anss); 
            st.push(nums[i]);
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};