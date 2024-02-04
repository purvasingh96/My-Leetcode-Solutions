class Solution {
public:
    int calculate(string s) {
        int res=0, lastNumber=0;
        int curr=0;
        char sign='+';
        
        for(int i=0;i<s.length();i++){
            if(isdigit(s[i])){
                curr = curr*10 + (s[i]-'0');
            }
            
            
            if(!isdigit(s[i]) && !iswspace(s[i]) || i == s.length() - 1){
                if(sign == '+' || sign == '-'){
                    res += lastNumber;
                    lastNumber = (sign == '+') ? curr : (-1 * curr);
                }
                else if(sign == '*'){
                    lastNumber = lastNumber*curr;
                }
                else if(sign == '/'){
                    lastNumber = lastNumber/curr;
                }
                
                sign = s[i];
                curr=0;
            }
        }
        
        res += lastNumber;
        return res;
    }
};