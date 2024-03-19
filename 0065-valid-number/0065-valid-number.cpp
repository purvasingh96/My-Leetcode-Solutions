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
    
    bool isDecimal(string s){
        if(s.length()==0){
            return false;
        }
        
        if(s[0] == '+' || s[0] == '-'){
            s = s.substr(1);
        }
        
        string left=s, right="";
        bool dotFound=false;
        for(int i=0;i<s.length();i++){
            if(s[i] == '.'){
                left = s.substr(0, i);
                right = s.substr(i+1);
                dotFound=true;
                break;
            }
        }
        if(!dotFound){
            return false;
        }
        
        return (oneOrMoreDigits(left) && right.length()==0) || 
            (oneOrMoreDigits(left) && oneOrMoreDigits(right)) || 
            (left.length()==0 && oneOrMoreDigits(right));   
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
    
    
public:
    bool isNumber(string s) {
        string left=s, right="";
        bool eFound=false;
        
        for(int i=0;i<s.length();i++){
            if(s[i] == 'e' || s[i] == 'E'){
                left = s.substr(0, i);
                right = s.substr(i+1);
                eFound=true;
                break;
            }
        }
        
        bool isDecimalOrInteger = isDecimal(left) || isInteger(left);
        if(eFound){
            return isDecimalOrInteger && isInteger(right);
        }
        
        return isDecimalOrInteger;
        
    }
};