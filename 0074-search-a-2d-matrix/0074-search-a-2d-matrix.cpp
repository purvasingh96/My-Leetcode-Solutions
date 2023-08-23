class Solution {
private:
    int binarySearchOnLastColumn(vector<vector<int>>& matrix, int target){
        int l=0, r=matrix.size()-1;
        int n = matrix[0].size();
        //cout<<r<<" "<<n;
        int ans=-1;
        while(l<r){
            int mid = l+ (r-l)/2;
            if(matrix[mid][n-1] >= target){
                ans=mid;
                r=mid-1;
            } else {
                l=mid+1;
            }
        }
        return matrix[l][n-1] >= target ? l : ans;
    }
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        // lower bound on last col
        int idx = binarySearchOnLastColumn(matrix, target);
        if(idx == -1) return false;
        //cout<<idx;
        return binary_search(matrix[idx].begin(), matrix[idx].end(), target);
        
    }
};