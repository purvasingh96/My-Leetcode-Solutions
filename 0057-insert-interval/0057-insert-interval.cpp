class Solution {
private:
    vector<int> getNewInterval(vector<int>& v1, vector<int> v2){
        vector<int> res;
        res.push_back(min(v1[0], v2[0]));
        res.push_back(max(v1[1], v2[1]));
        return res;
    }
    
    bool canMergeInterval(vector<int>& a, vector<int>& b){
        return min(a[1], b[1]) - max(a[0], b[0]) >= 0;
    }
    
    vector<vector<int>> insertIntervals(vector<vector<int>>& res, vector<vector<int>>& intervals, vector<int>& currInterval, int i){
        if(intervals.size() == 0){
            res.push_back(currInterval);
            return res;
        }
        
        int n = intervals.size();
        
        for(int j=0;j<i;j++){
                res.push_back(intervals[j]);
        }
        
        if(res.size() >0 && canMergeInterval(res.back(), currInterval)){
                vector<int> temp = res.back();
                res.pop_back();
                currInterval = getNewInterval(temp, currInterval);
        }
        
        while(i<n && canMergeInterval(intervals[i], currInterval)){
                currInterval = getNewInterval(intervals[i], currInterval);
                i+=1;
            }
            res.push_back(currInterval);
            
            for(int j=i;j<n;j++){
                res.push_back(intervals[j]);
            }
            return res;
    }
    
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& target) {
        
        int idx = upper_bound(intervals.begin(), intervals.end(), target) - intervals.begin();
        int n = intervals.size();
        
        vector<vector<int>> res;
        
        return insertIntervals(res, intervals, target, idx);
        
    }
};