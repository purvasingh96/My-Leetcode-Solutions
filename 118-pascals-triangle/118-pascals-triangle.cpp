class Solution {
public:
    vector<vector<int>> generate(int n) {
        vector<vector<int>> res;
        
        res.push_back({1});
        if(n==1) return res;
        res.push_back({1, 1});
        if(n==2) return res;
        
        for(int i=2;i<n;i++){
            
            vector<int> dp = res.back();
            
            vector<int> temp;
            temp.push_back({1});
            for(int j=0;j<dp.size()-1;j++){
                temp.push_back({dp[j]+dp[j+1]});
            }
            
            temp.push_back({1});
            res.push_back(temp);
        }
        
        return res;
        
    }
};