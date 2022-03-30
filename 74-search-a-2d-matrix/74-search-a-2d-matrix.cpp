class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int i;
        int n = matrix[0].size();
        
        int low = 0, high = matrix.size()-1;
        
        while(low <= high) {
            int mid = low + (high - low)/2;
            
            if(target >= matrix[mid][0] && target <= matrix[mid][matrix[mid].size()-1]) {
                i=mid;
                break;
            } else if(target < matrix[mid][0]) {
                high = mid-1;
            } else {
                low = mid+1;
            }
        }
        
        cout<<i;
        
        
        int left=0, right = matrix[i].size()-1;
        
        while(left<=right) {
            int mid = left + (right - left)/2;
            
            if(target == matrix[i][mid]) return true;
            
            else if(target > matrix[i][mid]) left = mid+1;
            else right = mid-1;
        }
        
        return false;
    }
};