class Solution {
public:
    bool isToeplitzMatrix(vector<vector<int>>& matrix) {
        int m =matrix.size(), n = matrix[0].size();
        vector<int> prev = matrix[0];
        
        for(int i=1;i<m;i++){
            for(int j=1;j<n;j++){
                if(matrix[i][j]!=prev[j-1]){
                    return false;
                }
            }
            prev = matrix[i];
        }
        
        return true;
    }
};