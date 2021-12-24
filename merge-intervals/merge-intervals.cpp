
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        // TC: O(nlogn) + O(n), dominant: O(nlogn)
        // SC: O(logn), sorting
        
        sort(intervals.begin(), intervals.end(), [](const vector<int>& a, const vector<int>&b) {
           if(a[0]!=b[0]) return a[0] < b[0];
            return a[1] < b[1];
        });
        
        vector<vector<int>> res;
        
        res.push_back(intervals[0]);
        
        for(int i=1;i<intervals.size();i++) {
            
            auto top = res.back();
            
            if(top[1] >= intervals[i][0]) {
                
                res.pop_back();
                
                vector<int> temp;
                temp.push_back(top[0]);
                
                top[1] >= intervals[i][1]?temp.push_back(top[1]):temp.push_back(intervals[i][1]);
                
                res.push_back(temp);
                
            } else {
                res.push_back(intervals[i]);
            }
            
        }
        
        return res;
    }
};