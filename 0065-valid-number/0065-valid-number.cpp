class Solution {
private:
    bool oneOrMoreDigits(string s){
        if(s.length()==0){
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
        if(s.length()==0){
            return false;
        }
        
        if(s[0] == '+' || s[0] == '-'){
            return oneOrMoreDigits(s.substr(1));
        }
        
        return oneOrMoreDigits(s);
    }
    
    bool isDecimal(string s){
        if(s.length() == 0){
            return false;
        }
        if(s[0] == '+' || s[0] == '-'){
            s = s.substr(1);
        }
            string left="", right="";
            int i=0;
            bool dotFound=false;
            
            for(;i<s.length();i++){
                if(s[i] == '.'){
                    dotFound = true;
                    break;
                } else {
                    left += s[i];
                }
            }
            if(!dotFound){
                return false;
            }
            right = s.substr(i+1);
            return ((oneOrMoreDigits(left) && right.length() == 0) ||
                   (oneOrMoreDigits(left) && oneOrMoreDigits(right)) ||
                   (left.length() == 0 && oneOrMoreDigits(right)));
        
    }
    
public:
    bool isNumber(string s) {
        string left="", right="";
        bool eFound=false;
        for(int i=0;i<s.length();i++){
            if(s[i] == 'e' || s[i] == 'E'){
                eFound=true;
                right = s.substr(i+1);
                break;
            } else {
                left += s[i];
            }
        }
        if(!eFound){
            return isDecimal(left) || isInteger(left);
        } else {
            return (isDecimal(left) || isInteger(left)) && (isInteger(right));
        }
    }
};