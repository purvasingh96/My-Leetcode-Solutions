class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> res;
        sort(intervals.begin(), intervals.end(), [](const vector<int>& a, const vector<int>& b){
            return a[0]<b[0];
        });
        
        for(auto curr:intervals){
            if(res.size()==0 || res.back()[1] < curr[0]){
                res.push_back(curr);
            } else {
                // last.end >= curr.start
                auto last = res.back();
                res.pop_back();
                res.push_back({last[0], max(last[1], curr[1])});
            }
        }
        
        return res;
    }
};