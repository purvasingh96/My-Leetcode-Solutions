class Solution {
public:
    vector<int> findBuildings(vector<int>& heights) {
        // monotonic decreasing queue
        vector<int> q;
        int maxheight = -1;
        
        
        for(int i=heights.size()-1;i>=0;i--) {
            
            if(maxheight < heights[i]) {
                q.push_back(i);
                maxheight = heights[i];
            }
            
            
        }
        
        reverse(q.begin(), q.end());
        
        return q;
    }
};