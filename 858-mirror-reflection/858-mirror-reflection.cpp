class Solution {
public:
    int mirrorReflection(int p, int q) {
        int m=1, n=1;
        
        while(m*p != n*q){
            n+=1;
            m = (n*q)/p;
        }
        
        if(m%2==0){
            return 0;
        } else {
            if(n%2==0) return 2;
            else return 1;
        }
        
    }
};