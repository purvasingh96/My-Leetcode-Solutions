class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        deque<pair<int, int>> q;
        
        sort(intervals.begin(), intervals.end(), [](const vector<int>& a, const vector<int>& b) {
            if(a[0]!=b[0]) return a[0] > b[0];
            return a[1] < b[1];
        });
        
        q.push_back(make_pair(intervals[0][0], intervals[0][1]));
        
        for(int i=1;i<intervals.size();i++) {
         

            
            if((intervals[i][0]<=q.back().first && q.back().second<=intervals[i][1])) {
                
                while(!q.empty() && (intervals[i][0]<=q.back().first && q.back().second<=intervals[i][1])) {
                    
                    q.pop_back();
                    
                }
                
            } 
            
            
                q.push_back(make_pair(intervals[i][0], intervals[i][1]));
            
            
        }
        
        return q.size();
    }
};