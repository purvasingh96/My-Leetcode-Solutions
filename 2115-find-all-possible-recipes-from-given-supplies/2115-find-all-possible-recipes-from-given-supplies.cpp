class Solution {
public:
    vector<string> findAllRecipes(vector<string>& recipes, vector<vector<string>>& ingredients, vector<string>& supplies) {
        map<string, int> indegree;
        map<string, vector<string>> adj;
        vector<string> ans;
        
        for(int i=0;i<recipes.size();i++){
            for(auto x:ingredients[i]){
                adj[x].push_back(recipes[i]);
                indegree[recipes[i]]+=1;
            }
        }

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
                    if(find(recipes.begin(), recipes.end(), r)!=recipes.end()){
                        ans.push_back(r);
                    }
                    q.push(r);
                }
            }
        }
        
        return ans;
    }
};