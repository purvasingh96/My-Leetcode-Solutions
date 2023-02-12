class Solution {
public:
    long long minimumFuelCost(vector<vector<int>>& roads, int seats) {
        
        unordered_map<int, int> degree;
    unordered_map<int, vector<int>> adj;
        
        for(auto r:roads){
            degree[r[0]]+=1;
            degree[r[1]]+=1;
            
            adj[r[0]].push_back(r[1]);
            adj[r[1]].push_back(r[0]);
        }
        
        int n = degree.size();
       vector<int> reps(n, 1);
        queue<int> q;
        for(int i=1;i<n;i++) {
            if(degree[i]==1) q.push(i);
        } 
        
        long long fuel=0;
        while(!q.empty()){
            auto f =q.front();
            q.pop();
            
            fuel += ceil((double)reps[f] / seats);
            
            for(auto c:adj[f]){
                degree[c] -=1;
                reps[c] += reps[f];
                if(degree[c] == 1 && c!=0){
                    q.push(c);
                }
            }
            
            
        }
        
        return fuel;
        
    }
};