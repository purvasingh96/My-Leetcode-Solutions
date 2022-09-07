class Solution {
private:
    int feasible(int threshold, int m, int n, int k){
        int total=0;
        for(int i=1;i<=m;i++){
            total += min(n, threshold/i);
            if(total >= k) return true;
        }
        return false;
    }
public:
    int findKthNumber(int m, int n, int k) {
        int left = 1, right=m*n;
        
        while(left<right){
            int mid = left + (right-left)/2;
            
            if(feasible(mid, m, n, k)){
                right=mid;
            } else left = mid+1;
        }
        
        return left;
    }
};