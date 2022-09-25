class Solution {
private:
    int returnLen(int n){
        int len=0;
        
        while(n/2!=0){
            n=n/2;
            len+=1;
        }
        
        return len+1;
    }
    
    
public:
    int concatenatedBinary(int n) {
        int res=0, mod=1e9+7;
        long long prev=1;
        
        for(int i=2;i<=n;i++){
            prev = prev*pow(2,returnLen(i));
            prev%=mod;
            prev += i;
        }
        
        return prev;
    }
};