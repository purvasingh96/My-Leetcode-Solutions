class Solution {
public:
    vector<string> findAllRecipes(vector<string>& recipes, vector<vector<string>>& ingredients, vector<string>& supplies) {
        map<string, int> indegree;
        map<string, vector<string>> adj;
        map<string, int> res;
        vector<string> ans;
        
        for(int i=0;i<recipes.size();i++){
            for(auto x:ingredients[i]){
                adj[x].push_back(recipes[i]);
                indegree[recipes[i]]+=1;
            }
        }
        
//         for(auto x:adj){
//             cout<<x.first<<" -> ";
//             for(auto y:x.second){
//                 cout<<y<<" ";
//             }
//             cout<<"\n";
//         }
        
//         for(auto x:indegree){
//             cout<<x.first<<" -> "<<x.second<<"\n";
//         }
        
        queue<string> q;
        
        for(auto s:supplies){
            q.push(s);
        }
        
        while(!q.empty()){
            string supply = q.front();
            q.pop();
            
            for(auto r:adj[supply]){
                indegree[r]-=1;
                if(indegree[r]==0) {
                    res[r]=true;
                    q.push(r);
                }
            }
        }
        
        for(auto r:recipes){
            if(res[r]){
                ans.push_back(r);
            }
        }
        return ans;
    }
};