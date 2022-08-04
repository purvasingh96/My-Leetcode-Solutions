class Solution {
private:
    // count, smallest_larger_than_mid, largest_smaller_than_mid
    vector<int> helper(vector<vector<int>>& matrix, int mid){
        vector<int> res(3, 0);
        res[1]=INT_MAX;
        res[2]=INT_MIN;
        int m=matrix.size(), n= matrix[0].size();
        int r = m-1, c=0;
        
        while(r>=0 && c<n){
            if(matrix[r][c] <= mid){
                res[2] = max(res[2], matrix[r][c]);
                res[0]+=(r+1);
                c+=1;
            } else {
                res[1] = min(res[1], matrix[r][c]);
                r-=1;
            }
        }
        
        return res;
    }
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int m=matrix.size(), n= matrix[0].size();
        int left=matrix[0][0], right=matrix[m-1][n-1];
        
        while(left<right)
        {
            int mid = left+(right-left)/2;
            
            auto res = helper(matrix, mid);
            int count= res[0];
            int mid_plus_1 = res[1];
            int mid_minus_1 = res[2];
            
            if(count==k) return mid_minus_1;
            if(count < k){
                left = mid_plus_1;
            } else {
                right = mid_minus_1;
            }
        } 
        
        return left;
    }
};