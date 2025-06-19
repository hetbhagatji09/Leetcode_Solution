class Solution {
public:
    int maxArea(vector<int>& height){
        int left=0;
        int n=height.size();
        int right=n-1;
        int max_area=INT_MIN;
        while(left<right){
            int h=min(height[left],height[right]);
            int w=right-left;
            max_area=max(max_area,h*w);
            if(height[left]< height[right]){
                left++;
            }
            else right--;
        }
        return max_area;
          
    }
};