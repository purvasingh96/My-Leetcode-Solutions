class Solution {
private:
    int canReach(vector<int>& bomb1, vector<int>& bomb2){
        int x1 = bomb1[0], y1 = bomb1[1], r1=bomb1[2];
        int x2 = bomb2[0], y2=bomb2[1], r2 = bomb2[2];
        
        return pow((x1-x2), 2) + pow((y1-y2), 2) <= pow(r1, 2);
    }
public:
    int maximumDetonation(vector<vector<int>>& bombs) {
        int n = bombs.size();
        vector<vector<int>> m(n);
        
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(canReach(bombs[i], bombs[j])){
                    m[i].push_back(j);
                }
            }
        }
        
        int ans=0;
        for(int i=0;i<n;i++){
            unordered_set<int> detonated;
            if(detonated.count(i)==0){
                detonated.insert(i);
                queue<int> q;
                q.push(i);
                
                while(!q.empty()){
                    auto f= q.front();
                    q.pop();
                    for(auto x:m[f]){
                        if(detonated.count(x)==0){
                            detonated.insert(x);
                            q.push(x);
                        }
                    }
                }
                
                ans = max(ans, (int)detonated.size());
                
            }
        }
        
        return ans;
        
    }
};