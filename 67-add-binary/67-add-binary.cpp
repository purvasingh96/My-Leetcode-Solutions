class Solution {
public:
    string addBinary(string a, string b) {
        int diff = a.length() - b.length();
        int extra = abs(diff);
        
        string c = a, d=b;
        
        if(diff!=0) {
         c = (a.length() > b.length() ? a : b);
         d = (a.length() <= b.length() ? a : b);   
        }
        
        string trail_zeros(extra, '0');
        
        d = trail_zeros + d;
        cout<<c<<" "<<d;
        
        int carry = 0;
        string res ="";
        
        for(int i=c.length()-1;i>=0;i--) {
            
            if(c[i] == '0' && d[i] == '0') {
                
                if(carry == 0) res += '0';
                else res += '1';
                
                carry = 0;
                
            } else if (c[i] == '1' && d[i] == '1') {
                
                if(carry == 0) res += '0';
                else res+= '1';
                
                carry = 1;
                
            } else if( (c[i] == '0' && d[i] == '1') || (c[i] == '1' && d[i] == '0') ) {
                
                if(carry == 0) res += '1';
                else {
                    res += '0';
                    carry = 1;
                }
                
                
            }
            
        }
        
        if(carry == 1) {
            res += '1';
        }
        
        reverse(res.begin(), res.end());
        return res;
    }
};