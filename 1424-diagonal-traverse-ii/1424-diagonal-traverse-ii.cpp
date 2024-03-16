class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& nums) {
        map<int, vector<int>> m;
        
        for(int i=0;i<nums.size();i++){
            for(int j=0;j<nums[i].size();j++){
                m[i+j].push_back(nums[i][j]);
            }
        }
        
        vector<int> ans;
        for(auto x:m){
            vector<int> res = x.second;
            for(int i=res.size()-1;i>=0;i--){
                ans.push_back(res[i]);
            }
        }
        
        return ans;
        
        
    }
};