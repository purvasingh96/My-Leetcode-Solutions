class Solution {
public:
    string getSmallestString(int n, int k) {
        string res = "";
        
        
        while(k>26 && (k-26) > n-1){
                
                res += "z";
                k-=26;
                n-=1;
                
            }
        //cout<<(k - (n))<<"\n";
            
            res += ((k - (n)) + 'a');
            
            n-=1;
            
            while(n>0) {
                res += 'a';
                n-=1;
            }
        
        reverse(res.begin(), res.end());
        return res;
        
        
    }
};