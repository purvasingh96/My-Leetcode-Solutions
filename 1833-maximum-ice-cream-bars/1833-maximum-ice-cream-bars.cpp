class Solution {
private:
    void dfs(int idx, int coins, int total, int n, int& maxN, vector<int>& costs){
        if(idx >= costs.size()) return;
        
        total += costs[idx];
        
        if(total <= coins){
           n+=1;
           maxN = max(maxN, n); 
            //cout<<"maxN: "<<maxN<<"\n";
        } 
        else total -= costs[idx];
        
        for(int i=idx+1;i<costs.size();i++){
            dfs(i, coins, total, n, maxN, costs);
        }
    }
public:
    int maxIceCream(vector<int>& costs, int coins) {
        int n=0, idx=0, total=0, maxN = 0;
        //dfs(idx, coins, total, n, maxN, costs);
        sort(costs.begin(), costs.end());
        //for(auto x:costs) cout<<x<<" ";
        
        for(idx;idx<costs.size();idx++){
            total += costs[idx];
            if(total > coins) break;
        }
        return idx;
    }
};