class Solution {
private:
    int dfs(int idx, int sum, int maxSum, vector<int>& valid, vector<bool>& visited, vector<vector<int>>& dp){
        
        if(idx >= valid.size() || visited[idx]) return 0;
        
        if(dp[idx][sum]!=-1) return dp[idx][sum];
        
        int skip = dfs(idx+1, sum, maxSum, valid, visited, dp);
        int dontSkip = -1;
        
        if(sum + valid[idx] <= maxSum && !visited[idx]){
            visited[idx]=true;
            dontSkip = 1 + dfs(idx+1, sum+valid[idx], maxSum, valid, visited, dp);
            visited[idx]=false;
        }
       
        
        return dp[idx][sum] = max(skip, dontSkip);
        
    }
    
public:
    int maxCount(vector<int>& banned, int n, int maxSum) {
        // valid pool
        set<int> nums(banned.begin(), banned.end());
        
        int k=0;
        
        
        int sum=0, c=0;
        
        for(int i=1;i<=n;i++){
            if(nums.count(i)==0 && sum + i <= maxSum){
                sum +=i;
                //if(sum >= maxSum) return c;
                c+=1;
            }
            
        }
        
        return c;
    }
};