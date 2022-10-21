
class Solution {
private:
    int sumTill(int n){
        return (n*(n+1))/2;
    }
public:
    int countOrders(int n) {
        int prev=1;
        int mod= 1e9+7;
        if(n==1) return 1;
        long prev_res = 1;
        
        for(int i=2;i<=n;i++){
            prev+=2;
            long sum = sumTill(prev);
            prev_res = sum*prev_res;
            prev_res %= mod;
            
        }
        
        return prev_res;
        
    }
};