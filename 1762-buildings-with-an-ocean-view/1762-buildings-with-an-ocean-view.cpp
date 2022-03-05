class Solution {
public:
    vector<int> findBuildings(vector<int>& heights) {
        // monotonic decreasing queue
        vector<int> q;
        
        q.push_back(0);
        
        for(int i=1;i<heights.size();i++) {
            
            if(heights[q.back()] <= heights[i]) {
                
                while(q.size()!=0 && heights[q.back()] <= heights[i]) {
                    q.pop_back();
                }
                
                
            }
            
            if(q.size()==0 || heights[q.back()] > heights[i]) {
                q.push_back(i);
            }
            
            
        }
        
        
        
        return q;
    }
};