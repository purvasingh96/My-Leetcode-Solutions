class Solution {

public:
    int maxPoints(vector<vector<int>>& points) {
        if(points.size()==1) return 1;
        if(points.size()==2) return 2;
        int res = 2;
        
        for(int i=0;i<points.size();i++){
            
            unordered_map<double, int> m;
            for(int j=0;j<points.size();j++){
                if(i!=j){
                    int x1 = points[i][0], y1 = points[i][1];
                    int x2 = points[j][0], y2 = points[j][1];

                    m[atan2(points[j][1] - points[i][1], points[j][0] - points[i][0])]++;
                    
                }
                
            }
            
            for(auto x:m){
                res = max(res, x.second+1);    
            }
            
        }
        return res;
    }
};