class Solution {
private:
    int fac[2010], inv[2010], invfac[2010];
    int mult(int a,int b){return (1ll*a*b)%mod;}
    int mod= 1e9+7;
    
    void helper(){
        fac[0] = invfac[0] = fac[1] = invfac[1] = inv[1] = 1;
        
        for(int i=2;i<2010;i++){
            fac[i] = mult(fac[i-1], i);
            inv[i] = mult(inv[mod%i], mod - mod/i);
            invfac[i] = mult(invfac[i-1], inv[i]);
        }
    }
    
    int ncr(int n, int r){
        if(r>n) return 0;
        return (((1LL*fac[n] * invfac[n-r]) % mod) * 1LL * invfac[r])%mod; 
    }
    
public:
    int numberOfSets(int n, int k) {
        helper();
        return ncr(n+k-1, 2*k);
    }
};