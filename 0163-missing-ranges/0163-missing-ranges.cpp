class Solution {
public:
    vector<vector<int>> findMissingRanges(vector<int>& nums, int lower, int upper) {
        int expected=lower;
        vector<vector<int>> ans;
        
        for(int i=0;i<nums.size();i++){
            if(nums[i] != expected){
                if(expected<=nums[i]-1){
                    ans.push_back({expected, nums[i]-1});    
                }
            } 
            expected = nums[i]+1;
        }
        
        if(expected <= upper){
            ans.push_back({expected, upper});
        }
        return ans;
    }
};