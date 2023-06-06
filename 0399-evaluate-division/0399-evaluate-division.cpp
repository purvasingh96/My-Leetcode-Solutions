class Solution {
private:
    double dfs(string u, string target, double val, unordered_map<string, vector<pair<string, double>>>& edges, unordered_map<string, bool> visited){
        //cout<<"u: "<<u<<" target: "<<target<<" val: "<<val<<"\n";
        if(u == target) return val;
        
        double ans = -1.0;
        if(!visited[u]){
            visited[u] = true;
            for(auto c:edges[u]){
                
                 double res = dfs(c.first, target, val*c.second, edges, visited);    
                if(res!=-1) return res;
            }
        }
        
        
        return ans;
    }
public:
    vector<double> calcEquation(vector<vector<string>>& e, vector<double>& v, vector<vector<string>>& q) {
        unordered_map<string, vector<pair<string, double>>> edges;
        vector<double> ans;
        unordered_map<string, bool> visited;
        
        for(int i=0;i<e.size();i++){
            string from = e[i][0], to = e[i][1];
            auto value = v[i];
            
            edges[from].push_back({to, value});
            edges[to].push_back({from, (double)1/value});
            visited[from] = false;
            visited[to] = false;
        }
        
        // for(auto x:edges){
        //     cout<<x.first<<" => ";
        //     for(auto y:x.second) cout<<y.first<<" "<<y.second<<"\n";
        // }
        
        for(int i=0;i<q.size();i++){
            string u = q[i][0], target = q[i][1];
            if(edges.find(u) == edges.end() || edges.find(target) == edges.end()) {
                ans.push_back(-1.0);
            } else {
                double result = dfs(u, target, 1.0, edges, visited);
                ans.push_back(result);
            }
            
        }
        
        return ans;
    }
};