class Solution {
private:
    bool topHalf(vector<vector<int>>& matrix){
        int r, c, num;
        for(int j=0;j<matrix[0].size();j++){
            r=0, c=j, num = matrix[r][c];
            while(r<matrix.size() && c<matrix[0].size()){
                if(matrix[r][c]!=num) return false;
                r+=1;
                c+=1;
            }
            
        }
        return true;
    }
    
    bool bottomHalf(vector<vector<int>>& matrix){
        int r, c, num;
        for(int i=1;i<matrix.size();i++){
            r = i, c=0, num = matrix[r][c];
            while(r<matrix.size() && c<matrix[0].size()){
                if(matrix[r][c]!=num) return false;
                r+=1;
                c+=1;
            }
        }
        return true;
    }
    
public:
    bool isToeplitzMatrix(vector<vector<int>>& matrix) {
        return topHalf(matrix) && bottomHalf(matrix);
    }
};