class Solution {
private:
    bool dfs(vector<int>& arr, int index, int count, int currsum, int k, int target, int& mask, unordered_map<int, bool>& memo) {
        
        if(count==k-1) return true;
        
        if(currsum > target) return false;
        
        if(memo.find(mask)!=memo.end()) return memo[mask];
        
        if(currsum==target){
            return memo[mask] = dfs(arr, 0, count+1, 0, k, target, mask, memo);
        }
        
        bool ans;
        for(int i=index;i<arr.size();i++){
            
            // not visied
            if(((mask >> i) & 1) == 0) {
                mask = (mask | (1<<i));
                
                ans = dfs(arr, i+1, count, currsum+arr[i], k, target, mask, memo);
                if(ans) return memo[mask] = true;
             
                
                mask = (mask ^ (1<<i));
                
            }
            
        }
        return memo[mask] = false;
        
        
    }
public:
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if(sum%k!=0) return false;
        sort(nums.begin(), nums.end(), greater<int>());
            
        int target = sum/k;
        int mask = 0;
        
        unordered_map<int, bool> memo;
        
        return dfs(nums, 0, 0, 0, k, target, mask, memo);
    }
};