class Solution {
public:
    vector<vector<int>> substringXorQueries(string s, vector<vector<int>>& queries) {
        vector<vector<int>> res;
        int n = s.length();
        
        map<int, vector<int>> m;
        
        for(int i=0;i<n;i++){
            long long curr=0;
            for(int j=i,power=0;j>=0 & power<32;power++,j--){
                int bits = (s[j]-'0');
                curr += (bits<<power);
                
                if(curr < INT_MAX && m.find(curr)==m.end()){
                    m[curr] = {j, i};
                }
                
            }
        }
        
        
        for(auto q:queries){
            int target= q[0]^q[1];
            //cout<<"target: "<<target<<"\n";
            if(m.find(target)==m.end()) res.push_back({-1, -1});
            else res.push_back(m[target]);
        }
        
        return res;
        
    }
};