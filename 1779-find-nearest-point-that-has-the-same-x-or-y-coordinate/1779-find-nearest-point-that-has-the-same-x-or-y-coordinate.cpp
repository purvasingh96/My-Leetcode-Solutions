#define pp pair<pair<int, int>, int>

class Solution {
private:
    bool isValid(pair<int, int> p, int x, int y){
        return p.first == x || p.second == y;
    }
public:
    int nearestValidPoint(int x, int y, vector<vector<int>>& points) {
        vector<pair<pair<int, int>, int>> res;
        
        for(int i=0;i<points.size();i++){
            res.push_back({{points[i][0], points[i][1]},i});
        }
        
        sort(res.begin(), res.end(), [&](const pp& a, const pp& b){
           
            int dist_a = abs(a.first.first - x) + abs(a.first.second - y);
            int dist_b = abs(b.first.first - x) + abs(b.first.second - y);
            
            if(dist_a == dist_b) return a.second < b.second;
            return dist_a < dist_b;
        });
        
        for(int i=0;i<res.size();i++){
            if(isValid(res[i].first, x, y)) return res[i].second;
        }
        
        return -1;
        
    }
};