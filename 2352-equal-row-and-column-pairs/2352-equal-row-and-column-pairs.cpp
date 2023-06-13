class Solution {
public:
    int equalPairs(vector<vector<int>>& grid) {
        unordered_map<string, pair<int, int>> m;
        int ans=0;
        
        for(int i=0;i<grid.size();i++){
            string s="";
            for(int j=0;j<grid[0].size();j++){
                s += to_string(grid[i][j])+"#";
            }
            m[s].first+=1;
        }
        
        for(int j=0;j<grid[0].size();j++){
            string s ="";
            for(int i=0;i<grid.size();i++){
                s += to_string(grid[i][j])+"#";
            }
            m[s].second+=1;
        }
        
        //for(auto x:m) cout<<x.first<<"->"<<x.second.first<<" "<<x.second.second<<"\n";
        
        for(auto x:m){
            ans += (x.second.first * x.second.second);
        }
        
        return ans;
    }
};