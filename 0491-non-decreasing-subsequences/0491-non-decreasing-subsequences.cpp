class Solution {
private:
    void backtrack(int idx, vector<int>& nums, vector<int> temp, set<vector<int>>& res){
        
        
        if(temp.size()>=2) res.insert(temp);
        
        if(idx>=nums.size()) return;
        
        for(int i=idx;i<nums.size();i++){
            if(temp.size()==0 || temp.back()<=nums[i]){
                temp.push_back(nums[i]);
                backtrack(i+1, nums, temp, res);
                temp.pop_back();
            }
            
        }
    }
public:
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        set<vector<int>> res;
        vector<int> temp;
        backtrack(0, nums, temp, res);
        
        
        return vector(res.begin(), res.end());
    }
};