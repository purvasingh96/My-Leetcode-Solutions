class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        // TC: O(NlogN) + O(N)
        // SC: O(1)
        
        // O(NlogN)
        sort(intervals.begin(), intervals.end());
        
        vector<vector<int>> ans;
        
        // O(N)
        for(int i=0;i<intervals.size();i++){
            if(ans.size() == 0 || ans.back()[1] < intervals[i][0]){
                ans.push_back(intervals[i]);
            } else {
                vector<int> back = ans.back();
                ans.pop_back();
                ans.push_back({min(back[0], intervals[i][0]), max(back[1], intervals[i][1])});
            }
        }
        
        return ans;
        
    }
};