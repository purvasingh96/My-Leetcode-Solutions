class Solution {
private:
    unordered_map<int, vector<int>> flatten(vector<vector<int>>& mat){
        unordered_map<int, vector<int>> m;
        for(int i=0;i<mat.size();i++){
            for(int j=0;j<mat[0].size();j++){
                if(mat[i][j]!=0){
                    m[i].push_back(j);
                }
            }
        }
        return m;
    }
public:
    vector<vector<int>> multiply(vector<vector<int>>& mat1, vector<vector<int>>& mat2) {
        
        auto a = flatten(mat1);
        auto b = flatten(mat2);
        int m = mat1.size(), n = mat1[0].size();
        int k = mat2[0].size();
        vector<vector<int>> res(m, vector<int>(k, 0));
        
        for(auto it: a){
            int row1 = it.first;
            for(auto col1:it.second){
                for(auto it2:b){
                    int row2 = it2.first;
                    for(auto col2:it2.second){
                        if(col1 == row2){
                            res[row1][col2] += mat1[row1][col1] * mat2[row2][col2];
                        }
                    }
                }
            }
        }
        
        return res;
    }
};