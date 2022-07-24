class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m=matrix.size(), n = matrix[0].size();
        
        int left=0, right=matrix.size()-1;
        int startrow=-1, endrow=-1;
        
        while(right>=0 && left<m && left<=right){
            int mid = left + (right-left)/2;
            if(matrix[mid][0] > target){
                right=mid-1;
            } else {
                left=mid+1;
            }
        }
        
        if(right<0 || (right>=0 && matrix[right][0] > target)) return false;
        else endrow = right;
        
        cout<<endrow;
        
        int i=0, j=endrow;
        
        while(i<n && j>=0 && i<j){
            int mid = i + (j-i)/2;
            
            if(matrix[mid].back() < target) {
                i=mid+1;
            } else {
                j=mid;
            }
        }
        
        
        
        if(matrix[j].back() < target) return false;
        else startrow = j;
        
        //cout<<startrow<<" "<<endrow;
        for(int k=startrow;k<=endrow;k++){
            
            int left=0, right=matrix[0].size();
            
            while(left<right){
                
                int mid = left + (right-left)/2;
                
                if(matrix[k][mid] < target){
                    left = mid+1;
                } else {
                    right=mid;
                }
                
            }
            
            if(matrix[k][left] == target) return true;
            
        }
        return false;
    }
};