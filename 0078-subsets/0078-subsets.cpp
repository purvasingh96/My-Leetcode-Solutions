class Solution {
private:
    void backtrack(int i, vector<int>& nums, vector<int>& temp, vector<vector<int>>& ans){
        if(i>=nums.size()){
            ans.push_back(temp);
            return;
        }
        
        // skip
        backtrack(i+1, nums, temp, ans);
        
        // dont skip
        temp.push_back(nums[i]);
        backtrack(i+1, nums, temp, ans);
        temp.pop_back();
        
    }
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> temp;
        
        backtrack(0, nums, temp, ans);
        
        return ans;
    }
};