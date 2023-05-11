class Solution {
private:
    void backtrack(vector<int>& nums, vector<int>& temp, vector<vector<int>>& res, unordered_set<int>& visited){
        if(temp.size()==nums.size()){
            res.push_back(temp);
            return;
        }
        
        for(int i=0;i<nums.size();i++){
            if(visited.count(nums[i]) == 0){
                visited.insert(nums[i]);
                temp.push_back(nums[i]);
                backtrack(nums, temp, res, visited);
                temp.pop_back();
                visited.erase(nums[i]);
            }    
        }
        
    }
public:
    vector<vector<int>> permute(vector<int>& nums) {
        //backtrack
        //N!
        vector<vector<int>> res;
        vector<int> temp;
        unordered_set<int> visited;
        backtrack(nums, temp, res, visited);
        return res;
    }
};