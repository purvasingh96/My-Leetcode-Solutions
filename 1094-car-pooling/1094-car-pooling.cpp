class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        vector<int> res(1001, 0);
        for(auto t:trips){
            int p = t[0], s=t[1], e=t[2];
            res[s]+=p;
            res[e]-=p;
        }
        
        int ans=res[0];
        for(int i=1;i<res.size();i++){
            res[i] += res[i-1];
            ans = max(ans, res[i]);
        }
        
        return ans <= capacity;
    }
};