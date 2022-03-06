class Solution {
public:
    int countOrders(int n) {
        if(n==1) return 1;
        
        
        int ans = 1;
        
        for(int i=1;i<=n;i++) {
            
            int x = 2*i-1;
            int sum=0;
            
            for(int j=1;j<=x;j++) {
                sum+=j;
            }
            
            long y = ans%(1000000007);
            
            ans = ((sum%1000000007)*y)%(1000000007);
            
        }
        
        
        return ans;
    }
};