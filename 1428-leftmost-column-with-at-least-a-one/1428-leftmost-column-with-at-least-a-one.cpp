/**
 * // This is the BinaryMatrix's API interface.
 * // You should not implement it, or speculate about its implementation
 * class BinaryMatrix {
 *   public:
 *     int get(int row, int col);
 *     vector<int> dimensions();
 * };
 */

class Solution {
private:
    int bs(int left, int right, int row, BinaryMatrix &bm){
        
        while(left<right){
            int mid = left+(right-left)/2;
            
            if(bm.get(row, mid) == 1){
                right=mid;
            } else left=mid+1;
            
            //cout<<left<<" "<<right<<"\n";
            
        }
        
        return bm.get(row, left)==1 ? left:INT_MAX;
    }
    
public:
    int leftMostColumnWithOne(BinaryMatrix &bm) {
        auto d = bm.dimensions();
        int m = d[0], n = d[1];
        //cout<<m<<" "<<n;
        int leftmost_col = n;
        
        for(int row=0;row<m;row++){
            
            leftmost_col = min(leftmost_col, bs(0, n-1, row, bm));
            //cout<<"leftmost_col: "<<leftmost_col<<"\n";
        }
        
        return leftmost_col==n ? -1:leftmost_col;
    }
};