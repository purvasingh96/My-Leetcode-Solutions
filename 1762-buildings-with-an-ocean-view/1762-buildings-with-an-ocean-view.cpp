class Solution {
public:
    vector<int> findBuildings(vector<int>& heights) {
        // monotonic decreasing queue
        deque<int> q;
        
        q.push_back(0);
        
        for(int i=1;i<heights.size();i++) {
            
            if(heights[q.back()] <= heights[i]) {
                
                while(!q.empty() && heights[q.back()] <= heights[i]) {
                    q.pop_back();
                }
                
                
            }
            
            if(q.empty() || heights[q.back()] > heights[i]) {
                q.push_back(i);
            }
            
            
        }
        
        vector<int> res;
        
        while(!q.empty()) {
            res.push_back(q.front());
            q.pop_front();

        }
        
        return res;
    }
};