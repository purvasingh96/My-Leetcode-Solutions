class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        // linesweep
        map<int, int> m;
        for(auto x:intervals){
            m[x[0]]+=1;
            m[x[1]]-=1;
        }
        
        int res=0;
        vector<vector<int>> ans;
        vector<int> temp;
        for(auto x:m){
            
            if(res==0){
                temp.push_back(x.first);
            }
            res+=x.second;
            if(res==0){
                temp.push_back(x.first);
                ans.push_back(temp);
                temp.clear();
            }
        }
        
        return ans;
        
    }
};