class Solution {
private:
    vector<int> topologicalSort(int k, vector<vector<int>>& cond){
        vector<int> topoSort;
        
        vector<int> indegree(k+1, 0);
        vector<vector<int>> adj(k+1);
        
        for(auto c:cond){
            int u= c[0], v=c[1];
            indegree[v]+=1;
            adj[u].push_back(v);
        }
        
        queue<int> q;
        
        for(int i=1;i<=k;i++){
            if(indegree[i] == 0) q.push(i);
        }
        
        if(q.size()==0) return topoSort;
        
        while(!q.empty()){
            
            auto f = q.front();
            q.pop();
            
            topoSort.push_back(f);
            
            for(auto child:adj[f]){
                indegree[child]-=1;
                if(indegree[child]==0) q.push(child);
            }
            
            
        }
        
        return topoSort;
        
    }
public:
    vector<vector<int>> buildMatrix(int k, vector<vector<int>>& rowConditions, vector<vector<int>>& colConditions) {
        
        vector<vector<int>> res(k, vector<int>(k, 0));
        
        vector<int> row = topologicalSort(k, rowConditions);
        if(row.size()!=k) return {};
        vector<int> col = topologicalSort(k, colConditions);
        if(col.size()!=k) return {};
        
        map<int, int> mc;
        
        for(int i=0;i<col.size();i++){
            mc[col[i]]=i;
        }
        
        
        for(int i=0;i<k;i++){
            res[i][mc[row[i]]] = row[i];
        }
        
        return res;
        
    }
};