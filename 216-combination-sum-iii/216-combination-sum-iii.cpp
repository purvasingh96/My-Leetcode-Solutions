class Solution {
public:
    void back_track(vector<int> temp, int k, int targetsum, vector<vector<int>>& res, int idx) {
        
        if(targetsum < 0 || temp.size()>k) return;
        
        if(temp.size()==k && targetsum==0) {
            res.push_back(temp);
            return;
        }
        
        for(int i=idx;i<=9;i++){
            
            temp.push_back(i);
            back_track(temp, k, targetsum-i, res, i+1);
            temp.pop_back();
            
        }
        
        
    }
    
    
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int> temp;
        vector<vector<int>> res;
        
        back_track(temp, k, n, res, 1);
        
        return res;
    }
};