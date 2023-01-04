class Solution {
// 13: 1 + x(10, 11)
private:
    int minCounts(int x){
        if(x==1) return INT_MIN;
        else if(x%3 == 0) return x/3;
        else if(x%2 == 0) return x/2;
        
        return  1 + min(minCounts(x - 2), minCounts(x-3));
    }
public:
    int minimumRounds(vector<int>& tasks) {
        int ans=0;
        unordered_map<int, int> m;
        for(auto x:tasks){
            m[x]+=1;
        }
        
        vector<int> res(1e5+1, 0);
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