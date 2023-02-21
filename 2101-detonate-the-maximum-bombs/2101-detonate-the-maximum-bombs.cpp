class Solution {
private:
    bool canReach(int x1, int x2, int y1, int y2, int r){
        return pow((x1-x2),2) + pow((y1-y2), 2) <= pow(r,2);
    }
    
    
public:
    int maximumDetonation(vector<vector<int>>& bombs) {
        int n = bombs.size();
        vector<vector<int>> m(n);
        
        
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                int x1 = bombs[i][0], y1=bombs[i][1];
                int x2 = bombs[j][0], y2=bombs[j][1];
                int r = bombs[i][2];
                
                if(canReach(x1, x2, y1, y2, r)){
                    m[i].push_back(j);
                }
            }
        }
        
        int ans=0;
        for(int i=0;i<m.size();i++){
            unordered_set<int> detonated;
            vector<int> bomb = bombs[i];
            
            if(detonated.count(i)==0){
                detonated.insert(i);
                queue<int> q;
                q.push(i);
                
                while(!q.empty()){
                    int sz = q.size();
                    while(sz--){
                        int f = q.front();q.pop();
                        
                        for(auto x:m[f]){
                            if(detonated.count(x)==0){
                                detonated.insert(x);
                                q.push(x);
                            }
                        }
                    }
                }
                
            }
            ans = max(ans, (int)detonated.size());
            
        }
        
        return ans;
        
    }
};