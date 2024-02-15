class Solution {
private:
    bool oneOrMoreDigits(string s){
        if(s.length() == 0) {
            return false;
        }
        for(int i=0;i<s.length();i++){
            if(!isdigit(s[i])){
                return false;
            }
        }
        
        return true;
    }
    
    bool isInteger(string s){
        if(s.length() == 0){
            return false;
        }
        return oneOrMoreDigits(s);
    }
    
    bool isDecimal(string s){
        
        for(int i=0;i<s.length();i++){
            if(s[i] == '.'){
                string left = s.substr(0, i);
                string right = s.substr(i+1);
                return (
                    isInteger(left) && right.length()==0 ||
                    isInteger(left) && oneOrMoreDigits(right) ||
                    left.length()==0 && oneOrMoreDigits(right)
                );
            }
        }
        
        return isInteger(s);
    }
public:
    bool isNumber(string s) {
        if(s[0] == '+' || s[0] == '-'){
            s=s.substr(1);
        }
        for(int i=0;i<s.length();i++){
            if(s[i] == 'e' || s[i]=='E'){ 
                if(i == 0){
                    return false;
                }
                string left = s.substr(0, i);
                string right = s.substr(i+1);
                if(right[0] == '+' || right[0] == '-'){
                    right = right.substr(1);
                }
                
                return (isInteger(left) || isDecimal(left)) && (isInteger(right));
            }
        }
        
        return (isInteger(s) || isDecimal(s));
    }
};