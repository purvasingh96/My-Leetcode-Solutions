class Solution {
public:
    void back_track(vector<int>& nums, vector<vector<int>>& res, vector<int>& temp, int idx, int target) {
        
        if(target == 0) {
            
            res.push_back(temp);
            return;
                
        } else if(target < 0) return;
        
        
        for(int i=idx;i<nums.size();i++) {
                            
                temp.push_back(nums[i]);

                back_track(nums, res, temp, i, target - nums[i]);
                
                temp.pop_back();
                
            
            
        }
        
    }
    
    
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        
        sort(candidates.begin(), candidates.end());
        
        vector<vector<int>> res;
        vector<int> temp;
      
        back_track(candidates, res, temp, 0, target);
        
        return res;
        
    }
    
    
    
    
    
    
    
    
    
    
};