class Solution {
public:
    int mySqrt(int x) {
        if(x==0) return 0;
        int left=0, right=x;
        long square;
        
        while(left<=right) {
            
            int mid = left + (right-left)/2;
            square = (long)mid*mid;
            if(square > x){
                right=mid-1;
            } else if(square < x){
                left=mid+1;
            } else {
                return mid;
            }
            
        }
        
        return right;
        
    }
};