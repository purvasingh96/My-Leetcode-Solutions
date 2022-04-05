class Solution {
public:
    int maxArea(vector<int>& height) {
        
        int left = 0, right = height.size()-1;
        int max_area = INT_MIN;
        
        while(left < right) {
            int ht = min(height[left], height[right]);
            int width = right - left;
            
            int cur_area = ht*width;
            
            max_area = max(max_area, cur_area);
            
            if(height[left] < height[right]) {
                
                int i = left;
                
                while(i<right && height[i]<=height[left]) {
                    i+=1;
                }
                
                left = i;
            } else {
                
                int i = right;
                
                while(i>left && height[i]<=height[right]) {
                    i-=1;
                }
                
                right=i;
                
            }
            
        }
        
        return max_area;
        
    }
};