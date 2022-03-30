class Solution {
public:
    string getSmallestString(int n, int k) {
        string res(n, ' ');
        
        int i=n-1;
        
        while(k>26 && (k-26) > n-1){
                
                res[i--] = 'z';
                k-=26;
                n-=1;
                
            }
        //cout<<(k - (n))<<"\n";
            
            res[i--] = ((k - (n)) + 'a');
            
            n-=1;
            
            while(n>0) {
                res[i--] = 'a';
                n-=1;
            }
        
        
        return res;
        
        
    }
};