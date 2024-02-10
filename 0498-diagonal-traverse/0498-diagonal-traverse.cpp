class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        bool leftToRight = true;
        
        map<int, vector<int>> m;
        for(int i=0;i<mat.size();i++){
            for(int j=0;j<mat[0].size();j++){
                m[(i+j)].push_back(mat[i][j]);
            }
        }
        
        vector<int> res;
        
        for(auto x:m){
            if(leftToRight){
                for(int i = x.second.size()-1;i>=0;i--){
                    res.push_back(x.second[i]);
                }
            } else {
                for(auto y:x.second){
                    res.push_back(y);
                }
            }
            
            leftToRight = !leftToRight;
        }
        
        return res;
    }
};