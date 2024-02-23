class Solution {
public:
    vector<vector<int>> findRLEArray(vector<vector<int>>& e1, vector<vector<int>>& e2) {
        
        vector<vector<int>> res;
        
        int i=0, j=0;
        
        while(i<e1.size() && j<e2.size()){
            int prod = e1[i][0] * e2[j][0];
            int freq;
            
            if(e1[i][1] < e2[j][1]){
                freq = e1[i][1];
                e2[j][1] -= e1[i][1];
                i+=1;
            } else if(e2[j][1] < e1[i][1]){
                freq = e2[j][1];
                e1[i][1] -= e2[j][1];
                j+=1;
            } else {
                freq =  e1[i][1];
                e1[i][1]=0;
                e2[j][1]=0;
                i+=1;
                j+=1;
            }
            
            if(res.size() > 0 && res.back()[0] == prod){
                freq += res.back()[1];
                res.pop_back();
            }
            res.push_back({prod, freq});
        }
        
        return res;
        
    }
};