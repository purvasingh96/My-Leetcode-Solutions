class Solution {
public:
    vector<vector<int>> diagonalSort(vector<vector<int>>& mat) {
        map<int, vector<vector<int>>> diff_to_indices;
        map<int, priority_queue<int, vector<int>, greater<int>>> diff_to_values;
        
        for(int i=0;i<mat.size();i++){
            for(int j=0;j<mat[0].size();j++){
                
                int diff = j-i;
                diff_to_indices[diff].push_back({i,j});
                diff_to_values[diff].push(mat[i][j]);
                
            }
        }
        
        
        for(auto x:diff_to_indices){
            
            int diff=x.first;
            vector<vector<int>> indices = x.second;
            
            for(int i=0;i<indices.size();i++){
                int r = indices[i][0];
                int c = indices[i][1];
                
                mat[r][c] = diff_to_values[diff].top();
                diff_to_values[diff].pop();
            }
            
        }
        
        return mat;
        
    }
};