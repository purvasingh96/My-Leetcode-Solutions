class Solution {

public:
    int minimumRounds(vector<int>& tasks) {
        int ans=0;
        unordered_map<int, int> m;
        int maxsize=INT_MIN;
        for(auto x:tasks){
            m[x]+=1;
            maxsize = max(maxsize, m[x]);
        }
        
        vector<int> res(maxsize+5, 0);
        res[0]=INT_MIN;
        res[1]=INT_MIN;
        res[2]=1;
        res[3]=1;
        res[4]=2;
        
        
        for(int i=5;i<res.size();i++){
            
            res[i] = 1 + min(res[i-2], res[i-3]);
        }
        
        
        for(auto x:m){
            
            auto c = res[x.second];
            //cout<<x.first<<" -> "<<x.second<<", c: "<<c<<"\n";
            if(c == INT_MIN) return -1;
            ans += c;
        }
        
        return ans;
        
    }
};