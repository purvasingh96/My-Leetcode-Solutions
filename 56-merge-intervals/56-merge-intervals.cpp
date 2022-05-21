
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        //sort intervals based on 1st elem
        // if x.second >= y.first => pop_back, merge new interval
        // else push_back(y)
        
        // TC: O(nlogn), SC: O(logn)
        vector<vector<int>> res;
        
        // O(nlogn), O(logn)
        sort(intervals.begin(), intervals.end(), [](const vector<int>& a, const vector<int>& b){
            return a[0] < b[0];
        });

        res.push_back(intervals[0]);
        // O(n), O(1)
        for(int i=1;i<intervals.size();i++) {
            
            auto x = res.back();
            auto y = intervals[i];
            
            if(x[1] < y[0]) {
                res.push_back(y);
            } else{
                
                vector<int> mergedInterval;
                mergedInterval.push_back(x[0]);
                if(y[1] < x[1]) mergedInterval.push_back(x[1]);
                else mergedInterval.push_back(y[1]);
                
                if(!res.empty()) res.pop_back();
                res.push_back(mergedInterval);
                
            }
   
            
        }
        
        return res;
        
    }
};