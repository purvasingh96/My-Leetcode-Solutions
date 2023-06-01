class Solution {
public:
    int diagonalSum(vector<vector<int>>& mat) {
        int n = mat[0].size();
        int sum = 0, target = mat[0].size()-1;
        
        for(int i=0;i<n;i++){
            // diagnol 1
            sum += mat[i][i];
            mat[i][i]=-1;
        }
        
        for(int i=0;i<n;i++){
            int res = mat[i][target-i];
            if(res!=-1){
                sum += res;
            }
        }
        
        return sum;
        
    }
};