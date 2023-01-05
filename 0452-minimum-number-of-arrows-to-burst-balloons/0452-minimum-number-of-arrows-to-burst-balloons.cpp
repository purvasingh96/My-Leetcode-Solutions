class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        sort(points.begin(), points.end());
        vector<vector<int>> res;
        
        for(auto x:points){
            if(res.size() == 0 || res.back()[1] < x[0]){
                res.push_back(x);
            } else {
                if(res.back()[1] >= x[0]){
                    vector<int> temp = res.back();
                    res.pop_back();
                    res.push_back({min(temp[0], x[0]), min(temp[1], x[1])});
                }
            }
        }
        
        return res.size();
    }
};