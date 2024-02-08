class Solution {
public:
    string addStrings(string num1, string num2) {
        string big = num1.length() > num2.length() ? num1 : num2;
        string small = num1.length() > num2.length() ? num2 : num1;
        string res="";
        int carry=0;
        int i=big.length()-1, j = small.length()-1;
        
        while(i>=0) {
            int s = j<0? carry : small[j]-'0'+carry;
            int sum = (big[i] - '0') + s;
            int digit = sum%10;
            carry = sum/10;
            res += (digit + '0');
            i-=1;
            j-=1;
        }
        
        if(carry){
            res += (carry+'0');
        }
        
        reverse(res.begin(), res.end());
        return res;
    }
};