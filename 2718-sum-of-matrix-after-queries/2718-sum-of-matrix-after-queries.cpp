class Solution {
public:
    long long matrixSumQueries(int n, vector<vector<int>>& queries) {
        
        long long ans=0, rsum=0, csum=0;
        
        unordered_map<int, int> r;
        unordered_map<int, int> c;
        
        for(int i=queries.size()-1;i>=0;i--){
            auto f = queries[i];
            int type=f[0], idx=f[1], val=f[2];
            
            if(type==0){
                // row
                if(r.find(idx)==r.end()){
                    rsum+=1;
                    r[idx]=val;
                    ans += (val)*(n - csum);
                }
            } else {
                if(c.find(idx) == c.end()){
                    csum +=1;
                    c[idx]=val;
                    ans += (val)*(n - rsum);
                }
            }
            
        }
        
        return ans;
        
    }
};