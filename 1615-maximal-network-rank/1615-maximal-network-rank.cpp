class Solution {
private:
    int returnRank(int i, int j, vector<int>& degree, vector<vector<int>>& adj){
        int res = degree[i] + degree[j];
        return adj[i][j]==1?res-1:res;
    }
    
public:
    int maximalNetworkRank(int n, vector<vector<int>>& roads) {
        vector<int> degree(n, 0);
        vector<vector<int>> adj(n, vector<int>(n, 0));
        
        for(int i=0;i<roads.size();i++){
            int u = roads[i][0], v = roads[i][1];
            degree[u]+=1;
            degree[v]+=1;
            adj[u][v]=1;
            adj[v][u]=1;
                
        }
        
        //for(int i=0;i<n;i++) cout<<degree[i]<<" ";
        
        int maxRank=INT_MIN;
        
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
               maxRank = max(maxRank, returnRank(i, j, degree, adj));
            }
        }
        
        return maxRank;
        
    }
};