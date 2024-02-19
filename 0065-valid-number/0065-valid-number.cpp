class Solution {
private:
    bool isOneOrMoreDigits(string s){
        if(s.length()==0) return false;
        for(int i=0;i<s.length();i++){
            if(!isdigit(s[i])){
                return false;
            }
        }
        return true;
    }
    
    bool isInteger(string s){
        if(s.length()==0) return false;
        if(s[0] == '+' || s[0] == '-'){
            return isOneOrMoreDigits(s.substr(1));
        }
        return isOneOrMoreDigits(s);
    }
    
    bool isDecimal(string s){
        if(s.length()==0) return false;
        if(s[0] == '+' || s[0] == '-'){
            return isDecimal(s.substr(1));
        }
        
        string left="", right="";
        for(int i=0;i<s.length();i++){
            if(s[i] == '.'){
                left = s.substr(0, i);
                right = s.substr(i+1);
                break;
            }
        }
        
        return isOneOrMoreDigits(left) && right.length()==0 || 
            isOneOrMoreDigits(left) && isOneOrMoreDigits(right) ||
            left.length()==0 && isOneOrMoreDigits(right);
        
    }
public:
    bool isNumber(string s) {
        string left="", right="";
        for(int i=0;i<s.length();i++){
            if(s[i] == 'E' || s[i]=='e'){
                left = s.substr(0, i);
                right = s.substr(i+1);
                break;
            }
        }
        cout<<"left: "<<left<<" right: "<<right;
        if(right.length()==0){
            // no e's
            cout<<"here";
            cout<<"isDecimal(s):: "<<isDecimal(s)<<"\n";
            cout<<"isInteger(s):: "<<isInteger(s)<<"\n";
            return isDecimal(s) || isInteger(s);
        }
        
        return (isDecimal(left) || isInteger(left)) && isInteger(right);
    }
};