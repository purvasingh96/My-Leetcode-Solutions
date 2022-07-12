class Solution {
private:
    bool dfs(int idx, int cur_sum, int target, int k, vector<int>& nums, vector<bool>& visited){
        
        if(k==1) return true;
        
        if(idx>=nums.size()) return false;
        
        if(cur_sum == target){
            return dfs(0, 0, target, k-1, nums, visited);
        }
        
        for(int j=idx;j<nums.size();j++){
            
            if(visited[j] || cur_sum+nums[j] > target) continue;
            
            visited[j] = true;
            
            if(dfs(j+1, cur_sum+nums[j], target, k, nums, visited)){
                return true;
            }
            
            visited[j]=false;
            
        }
        
        return false;
        
    }
public:
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end(), greater<int>());
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if(sum%k!=0) return false;
        vector<bool> visited((int)nums.size(), false);
        int target = sum/k;
        
        return dfs(0, 0, target, k, nums, visited);
    }
};