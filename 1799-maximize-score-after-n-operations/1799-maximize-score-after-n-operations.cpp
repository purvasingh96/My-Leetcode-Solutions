class Solution {
private:
    int dfs(int op, vector<bool>& visited, vector<int>& nums, unordered_map<vector<bool>, int>& dp){
        if(dp.find(visited)!=dp.end()) return dp[visited];
        
        int maxScore=0;
        for(int i=0;i<nums.size();i++){
            if(visited[i]) continue;
            for(int j=i+1;j<nums.size();j++){
                if(!visited[j]){
                    visited[i]=true;
                    visited[j]=true;
                    int score = op * (__gcd(nums[i], nums[j]));
                    int totalScore = score + dfs(op+1, visited, nums, dp);
                    maxScore = max(maxScore, totalScore);
                    visited[j]=false;
                    visited[i]=false;
                }
            }
        }
        
        return dp[visited] = maxScore;
    }
public:
    int maxScore(vector<int>& nums) {
        unordered_map<vector<bool>, int> dp;
        vector<bool> visited(nums.size(), false);
        return dfs(1, visited, nums, dp);
    }
};