class Solution {
private:
    void dfs(int node, int parent, vector<vector<int>>& g, vector<vector<int>>& dp, vector<int>& ans, string& labels){
        
        dp[node][labels[node]-'a']+=1;
        
        for(auto child:g[node]){
            if(child!=parent){
                dfs(child, node, g, dp, ans, labels);
                for(int i=0;i<27;i++){
                    dp[node][i] += dp[child][i];
                }
            }
        }
        ans[node] = dp[node][labels[node] - 'a'];
    }
public:
    vector<int> countSubTrees(int n, vector<vector<int>>& edges, string labels) {
        vector<vector<int>> m(n);
        vector<int> res;
        
        for(auto x:edges){
            m[x[0]].push_back(x[1]);
            m[x[1]].push_back(x[0]);
        }
        
        vector<vector<int>> dp(n, vector<int>(27, 0));
        vector<int> ans(n);
        
        dfs(0, -1, m, dp, ans, labels);
        
        return ans;
        
    }
};