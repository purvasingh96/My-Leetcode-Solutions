class Solution {
public:
    vector<vector<int>> findMissingRanges(vector<int>& nums, int lower, int upper) {
        int expected=lower;
        vector<vector<int>> res;
        
        for(int i=0;i<nums.size();i++){
            
                if(expected <= nums[i]-1){
                    res.push_back({expected, nums[i]-1});    
                }
                
            
            expected = nums[i]+1;
        }
        
            if(expected <= upper){
                res.push_back({expected, upper});    
            }
            
        
        
        return res;
    }
};