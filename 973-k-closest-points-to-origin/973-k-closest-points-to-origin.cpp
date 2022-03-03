class Solution {
public:
    int getDist(vector<int> points) {
        int x = points[0];
        int y = points[1];
        return (pow(x, 2) + pow(y, 2));
    }
    
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        
        priority_queue<pair<int, int>> pq;
        
        for(int i=0;i<points.size();i++) {
            
            auto entry = make_pair(getDist(points[i]), i);
            
            if(pq.size() < k) {
                pq.push(entry);
                        
            } else if(entry.first < pq.top().first) {
                
                pq.pop();
                pq.push(entry);
                
            }
            
        }
        
        vector<vector<int>> res;
        
        while(pq.size()!=0) {
            res.push_back(points[pq.top().second]);
            pq.pop();
        }
        
        return res;
        
    }
};