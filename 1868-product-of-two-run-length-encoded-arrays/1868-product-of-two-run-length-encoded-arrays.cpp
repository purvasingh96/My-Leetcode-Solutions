class Solution {
public:
    vector<vector<int>> findRLEArray(vector<vector<int>>& e1, vector<vector<int>>& e2) {
        int i=0, j=0;
        vector<vector<int>> res;
        while(i<e1.size() && j<e2.size()){
            int val, count;
            val = e1[i][0] * e2[j][0];
            
            if(e2[j][1] > e1[i][1]){
                e2[j][1] -= e1[i][1];                
                count = e1[i][1];
                i+=1;
            } else if(e1[i][1] > e2[j][1]) {
                e1[i][1] -= e2[j][1];
                count =e2[j][1];
                j+=1;
            } else if(e1[i][1] == e2[j][1]){
                count = e1[i][1];
                e1[i][1]=0;
                e2[j][1]=0;
                i+=1;
                j+=1;
            }
            
            if(res.size()!=0 && res.back()[0] == val){
                // combine
                auto back = res.back();
                res.pop_back();
                count += back[1];
            }
            
            res.push_back({val, count});
        }
        
        return res;
    }
};