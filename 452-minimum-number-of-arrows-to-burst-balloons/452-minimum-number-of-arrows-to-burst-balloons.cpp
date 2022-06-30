class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& p) {
        sort(p.begin(), p.end(), [](const vector<int>& a, const vector<int>& b){
           return a[0]<b[0]; 
        });
        
        vector<vector<int>> q;
        
        q.push_back(p[0]);
        
        for(int i=1;i<p.size();i++){
            
            if(p[i][0] <= q.back()[1]){
                
                int a = min(q.back()[0], p[i][0]);
                int b = min(q.back()[1], p[i][1]);
                
                q.pop_back();
                q.push_back({a,b});
                
            } else {
                q.push_back(p[i]);
            }
            
        }
        
        return q.size();
    }
};