class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        vector<vector<int>> res;
        res.push_back(intervals[0]);
        
        for(int i=1;i<intervals.size();i++){
            if(intervals[i][0]<=res.back()[1]){
                // merge
                auto a = intervals[i], b = res.back();
                res.pop_back();
                res.push_back({min(a[0], b[0]), max(a[1], b[1])});
            } else res.push_back(intervals[i]);
        }
        return res;
    }
};