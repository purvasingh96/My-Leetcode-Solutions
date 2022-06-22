class Solution {
private:
    int dfs(int idx, vector<int>& balance){
        
        while(idx<balance.size() && balance[idx]==0){
            idx+=1;
        }
        
        if(idx == balance.size()){
            return 0;
        }
        
        int mint = INT_MAX;
        
        for(int i=idx+1;i<balance.size();i++){
            
            if(balance[i]*balance[idx] < 0){
                
                balance[i]+=balance[idx];
                
                mint = min(mint, 1+dfs(idx+1, balance));
                
                balance[i] -= balance[idx];
                
            }
            
        }
        
        return mint;
        
    }
public:
    int minTransfers(vector<vector<int>>& transactions) {
        map<int, int> m;
        
        for(auto x:transactions){
            
            m[x[0]] += x[2];
            m[x[1]] -= x[2];
            
        }
        int n = m.size();
        vector<int> balance(n, 0);
        int i=0;
        for(auto x:m){
            balance[i++] += x.second;
        }
        
        return dfs(0, balance);
    }
};