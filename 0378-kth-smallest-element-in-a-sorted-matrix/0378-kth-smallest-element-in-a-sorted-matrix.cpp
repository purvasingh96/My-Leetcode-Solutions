class Solution {
private:
    int count(vector<vector<int>>& matrix, int mid, vector<int>& smallLargePair){
        int co=0;
        
        int n = matrix.size();
        int r=n-1, c=0;
        
        while(r>=0 && c<n){
            if(matrix[r][c] > mid){
                smallLargePair[1] = min(smallLargePair[1], matrix[r][c]);
                r--;
            } else {
                smallLargePair[0] = max(smallLargePair[0], matrix[r][c]);
                co += r+1;
                c+=1;
            }
        }
        
        return co;
        
    }
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int n = matrix.size();
        int l=matrix[0][0], r = matrix[n-1][n-1];
        
        while(l<r){
            int mid = l+(r-l)/2;
            vector<int> smallLargePair = {matrix[0][0], matrix[n-1][n-1]};
            
            int ck = count(matrix, mid, smallLargePair);
            
            if(ck == k){
                return smallLargePair[0];
            }
            
            if(ck < k){
                l = smallLargePair[1];
            } else {
                r = smallLargePair[0];
            }
            
        }
        
        return l;
        
    }
};