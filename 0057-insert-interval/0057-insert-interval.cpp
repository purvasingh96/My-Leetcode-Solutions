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
        int n = intervals.size();
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
        cout<<idx;
        
        if(idx==0){
            //res.push_back(target);
            int i=0;
            vector<int> currInterval = target;
            return insertIntervals(res, intervals, currInterval, i);
            
        } else if(idx == n) {
            for(int j=0;j<n;j++){
                res.push_back(intervals[j]);
            }
            
            if(canMergeInterval(res.back(), target)){
                res.pop_back();
                res.push_back(getNewInterval(intervals.back(), target));
            } else{
                res.push_back(target);
            }
            
            return res;
            
        } else {
            
            // idx between 0 to n-1
            for(int j=0;j<idx;j++){
                    res.push_back(intervals[j]);
                }
            vector<int> currInterval = target;
            
            if(canMergeInterval(res.back(), target)){
                vector<int> temp = res.back();;
                res.pop_back();
                currInterval = getNewInterval(temp, target);
            } 
            
            int i=idx;
            
            return insertIntervals(res, intervals, currInterval, i);
            
        }
        
        
    }
};