class Solution {
private:
    vector<vector<pair<int, int>>> flatten(vector<vector<int>>& mat){
        int m = mat.size(), n=mat[0].size();
        vector<vector<pair<int, int>>> res(m, vector<pair<int, int>>(n));
        
        for(int i=0;i<mat.size();i++){
            for(int j=0;j<mat[0].size();j++){
                if(mat[i][j]!=0){
                    res[i].push_back({mat[i][j], j});
                }
            }
        }
        return res;
    }
public:
    vector<vector<int>> multiply(vector<vector<int>>& mat1, vector<vector<int>>& mat2) {
        auto a = flatten(mat1);
        auto b = flatten(mat2);
        int m = mat1.size(), n=mat1[0].size(), k=mat2[0].size();
        vector<vector<int>> res(m, vector<int>(k, 0));
        
        for(int row=0;row<a.size();row++){
            for(auto r:a[row]){
                int valA = r.first, col_ = r.second;
                for(auto bc:b[col_]){
                    int valB = bc.first, col = bc.second;
                    res[row][col] += valA*valB; 
                }
            }
        }
        
        return res;
        
    }
};