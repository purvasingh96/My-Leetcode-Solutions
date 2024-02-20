class Solution {
private:
    void backtrack(vector<int>& nums, int i, vector<int>& temp, vector<vector<int>>& res){
        if(i>=nums.size()) {
            res.push_back(temp);
            return;
        }
        
        //skip
        backtrack(nums, i+1, temp, res);
        // dont skip
        temp.push_back(nums[i]);
        backtrack(nums, i+1, temp, res);
        temp.pop_back();
        
    }
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> temp;
        backtrack(nums, 0, temp, res);
        return res;
    }
};