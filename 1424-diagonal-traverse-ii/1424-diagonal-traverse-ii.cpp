class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& nums) {
        queue<pair<int, int>> q;
        q.push({0, 0});
        vector<int> ans;
        
        int m = nums.size();
        while(!q.empty()){
            auto f = q.front();
            q.pop();
            int row=f.first, col=f.second;
            ans.push_back(nums[row][col]);
            if(col==0 && row+1<m){
                q.push({row+1, col});
            }
            
            if(col+1<nums[row].size()){
                q.push({row, col+1});
            }
            
        }
        
        return ans;
        
    }
};