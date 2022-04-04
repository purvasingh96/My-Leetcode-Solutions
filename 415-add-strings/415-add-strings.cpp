class Solution {
public:
    string addStrings(string num1, string num2) {
        string temp = num1;
       if(num2.length() > num1.length()) {
           swap(num1, num2);
       }
        
        int n = num1.length();
        
        string res (n+1, ' ');
        
        int i=num1.length()-1, j=num2.length()-1;
        int carry = 0;
        int k = res.length()-1;
        
        while(i>=0 && j>=0) {
            
            int sum = (num1[i]-'0') + (num2[j] - '0') +carry;
            carry = sum/10;
            res[k] = (sum%10) + '0';
            i-=1;
            j-=1;
            k-=1;
            
        }
        
        //cout<<i<<" "<<k;
        
        if(i>=0) {
            while(i>=0) {
                
                int sum = (num1[i]-'0') + carry;
                //cout<<sum;
                //cout<<"k: "<<k<<"sum%10: "<<sum%10<<"\n";
                res[k] = sum%10 + '0';
                //cout<<"res["<<k<<"]: "<<res[k]<<"\n";
                carry = sum/10;
                i-=1;
                k-=1;
            }
        }
        
        //cout<<"res[1]: "<<res[1];
        if(carry!=0) {
            res[k]=carry+'0';
            return res;
        }
        return res.substr(1);
        
        
        
        
    }
};