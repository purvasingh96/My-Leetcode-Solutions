class Solution {
public:
    int reachableNodes(int n, vector<vector<int>>& edges, vector<int>& r) {
        map<int, vector<int>> m;
        int c=0;
        map<int, bool> visited;
        
        map<int, bool> not_pick;
        
        for(int i=0;i<n;i++){
            not_pick[i]=false;
        }
        
        for(auto x:r){
            not_pick[x] = true;
        }
        
        
        for(auto e:edges){
            m[e[0]].push_back(e[1]);
            m[e[1]].push_back(e[0]);
        }
        
        queue<int> q;
        q.push(0);
        visited[0] = true;
        
        while(!q.empty()){
            
            int s = q.size();
            
            for(int i=0;i<s;i++){
                
                auto f = q.front();
                q.pop();
                visited[f] = true;
                
                for(auto k:m[f]){
                    if(!not_pick[k] && !visited[k]){
                        c+=1;
                        q.push(k);
                    }
                }
                
            }
            
        }
        
        return c+1;
        
    }
};