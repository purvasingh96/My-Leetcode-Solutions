class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int max_area = 0;
        deque<int> q;
        q.push_back(-1);
        
        for(int i=0;i<heights.size();i++) {
            
            if(q.back() == -1 || heights[q.back()] <= heights[i]) {
                
                q.push_back(i);
                
            } else {
                
                while(q.back()!=-1 && heights[q.back()] > heights[i]) {
                    
                    int cur_height = heights[q.back()];
                    q.pop_back();
                    int cur_width = (i - q.back() - 1);
                    int cur_area = cur_height * cur_width;
                    
                    max_area = max(max_area, cur_area);
                    
                }
                
                q.push_back(i);
                
            }
            
        }
        
        while(q.back() != -1) {
            
                    int cur_height = heights[q.back()];
                    q.pop_back();
                    int cur_width = (heights.size() - q.back() - 1);
                    int cur_area = cur_height * cur_width;
                    
                    max_area = max(max_area, cur_area);
            
            
        }
        
        return max_area;
        
    }
};