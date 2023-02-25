class Solution {
private:
    void dfs(vector<int>& nums, int left, int right, int k, vector<int>& path, long long target, vector<vector<int>>& ans){
        
        if(k==2){
            
            while(left<right){
                int sum = nums[left] + nums[right];
                if(sum == target){
                    path.push_back(nums[left]);
                    path.push_back(nums[right]);
                    ans.push_back(path);
                    path.pop_back();
                    path.pop_back();
                    left+=1;
                    right-=1;
                    while(left<right && nums[left]==nums[left-1]){
                        left+=1;
                    }
                    
                }
                else if(sum > target){
                    right-=1;
                } else{
                    left+=1;
                }
            }
            
        }
        
        while(left<right){
            path.push_back(nums[left]);
            dfs(nums,left+1, right, k-1, path, target-nums[left], ans);
            path.pop_back();
            while(left<right && nums[left]==nums[left+1]){
                left+=1;
            }
            left+=1;
        }
        
        
    }
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        vector<int> path;
        vector<vector<int>> ans;
        int n = nums.size();
        dfs(nums, 0, n-1, 4, path, target, ans);
        return ans;
    }
};