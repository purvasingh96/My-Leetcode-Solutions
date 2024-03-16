class Solution {
public:
    int myAtoi(string s) {
        if(s.length() == 0){
            return 0;
        }
        
        // trailing whitespace
        if(s[0] == ' '){
           for(int i=0;i<s.length();i++){
            if(s[i]!=' '){
                if(i>0){
                    s = s.substr(i);
                    break;
                }
                
            }
        } 
        }
        
        
        bool isNeg=false;
        if(s.length() > 0 && s[0] == '-'){
            isNeg=true;
        }
        
        double d=0, i=0;
        if(isNeg || s[0] == '+'){
            i=1;
        }
        for(;i<s.length();i++){
            if(!isdigit(s[i])){
                break;
            } else {
                 d= d*10 + (s[i] - '0');
            }
        }
        
        if(isNeg){
            d = d*-1;
        }
        
        if(d > INT_MAX){
            d = INT_MAX;
        }
        
        if(d < INT_MIN){
            d = INT_MIN;
        }
        
        return d;
        
    }
};