class Solution {
public:
    int maxArea(vector<int>& height) {
        int left=0, right=height.size()-1;
        int maxArea = 0;
        while(left<right){
            int w = right-left;
            int h = min(height[left], height[right]);
            maxArea = max(maxArea, h*w);
            if(height[left] < height[right]){
                left+=1;
            } else {
                right-=1;
            }
        }
        
        return maxArea;
        
    }
};