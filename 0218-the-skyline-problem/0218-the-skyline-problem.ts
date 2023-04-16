class Solution {
public:
    vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {
        multiset<int> fallbackHeight;
        vector<vector<int>> res;
        vector<vector<int>> ans;
        
        for(auto b:buildings){
            res.push_back({b[0], -b[2]});
            res.push_back({b[1], b[2]});
        }
        
        sort(res.begin(), res.end());
        fallbackHeight.insert(0);
        int maxHeight=0;
        
        for(int i=0;i<res.size();i++){
            int pos = res[i][0], ht = res[i][1];
            //cout<<"i: "<<i<<"\n";
            // for(auto x:fallbackHeight) cout<<x<<" ";
            // cout<<"\n";
            if(ht < 0){
                fallbackHeight.insert(-ht);
            } else {
                
                fallbackHeight.erase(fallbackHeight.find(ht));
                
            }
            
            
            if(maxHeight == *fallbackHeight.rbegin()){
                continue;
            } else {
                maxHeight=*fallbackHeight.rbegin();
                ans.push_back({pos, maxHeight});
            }
            
        }
        return ans;
        
    }
};