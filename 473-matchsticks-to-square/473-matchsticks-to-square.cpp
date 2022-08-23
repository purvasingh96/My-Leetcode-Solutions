class Solution {
private:
    bool dfs(vector<int>& arr, int idx, int count, int cursum, int target, int& mask, unordered_map<int, bool>& memo){
        
        if(count==3) return true;
        
        if(cursum > target) return false;
        
        if(memo.find(mask)!=memo.end()) return memo[mask];
        
        if(cursum == target){
            return memo[mask] = dfs(arr, 0, count+1, 0, target, mask, memo);
        }
        
        for(int i=idx;i<arr.size();i++){
            
            if(((mask >> i) & 1) == 0){
                
                mask = (mask | (1<<i));
                bool ans = dfs(arr, idx+1, count, cursum+arr[i], target, mask, memo);
                if(ans) return memo[mask] = true;
                mask = (mask ^ (1<<i));
                
                
            }
            
            
        }
        
        return memo[mask] = false;
        
    }
public:
    bool makesquare(vector<int>& matchsticks) {
        
        int sum = accumulate(matchsticks.begin(), matchsticks.end(), 0);
        
        if(sum%4!=0) return false;
        
        int target = sum/4, mask=0;
        
        unordered_map<int, bool> memo;
        
        return dfs(matchsticks, 0, 0, 0, target, mask, memo);
    }
};