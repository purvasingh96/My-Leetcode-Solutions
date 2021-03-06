class Solution {
public:
    double myPow(double x, int n) {
        
        long long N = n;
        
        if(N<0) {
            x = 1/x;
            N = -N;
        }
        
        double ans = 1, cp=x;
        
        for(long long i=N;i;i/=2) {
            
            if(i%2!=0) {
                ans = ans * cp;
            }
            
            cp = cp * cp;
            
        }
        
        return ans;
        
        
    }
};