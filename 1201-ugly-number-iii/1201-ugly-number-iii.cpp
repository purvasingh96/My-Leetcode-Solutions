class Solution {

public:
    int nthUglyNumber(int n, int A, int B, int C) {
        long long left=1, right=2e9;
        long a = (long)A, b=(long)B, c=(long)C;
        while(left<right){
            
            long long mid = left + (right-left)/2;
            
            long long count = mid/a + mid/b + mid/c - mid/lcm(a,b) - mid/lcm(b, c) - mid/lcm(c, a) + mid/lcm(a, lcm(b, c));
            
            if(count < n){
                left=mid+1;
            } else {
                right=mid;
            }
            
        }
        
        return left;
    }
};