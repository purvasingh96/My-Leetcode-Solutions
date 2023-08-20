class Solution {
private:
    void backtrack(int i, vector<int>& nums, vector<int>& temp, unordered_map<int, bool>& visited, vector<vector<int>>& res){
        
        if(temp.size()==nums.size()){
            res.push_back(temp);
            return;
        }
        
        
        for(int k=0;k<nums.size();k++){
            if(!visited[nums[k]]){
                visited[nums[k]] = true;
                temp.push_back(nums[k]);
                backtrack(k, nums, temp, visited, res);
                temp.pop_back();
                visited[nums[k]]=false;
            }
        }
        
    }
public:
    vector<vector<int>> permute(vector<int>& nums) {
        unordered_map<int, bool> visited;
        for(int i=-10;i<=10;i++) visited[i]=false;
        vector<int> temp;
        vector<vector<int>> res;
        backtrack(0, nums, temp, visited, res);
        return res;
    }
};