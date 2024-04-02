class Solution {
private:
    
public:
    int myAtoi(string s) {
        if(s.length()==0){
            return 0;
        }
        int j=0;
        while(j<s.length() && s[j] == ' '){
            j+=1;
        }
        if(j==s.length()){
            return 0;
        }
        
        char op = '+';
        if(s[j] == '-'){
            op = '-';
            j+=1;
        } else if(s[j] == '+'){
            j+=1;
        }
        
        double d=0;
        while(j<s.length() && isdigit(s[j])){
            d=d*10+s[j]-'0';
            j+=1;
        }
        cout<<d;
        if(op == '-'){
            d = d*-1;
        }
        
        if(d>INT_MAX){
            return INT_MAX;
        }
        
        if(d<INT_MIN){
            return INT_MIN;
        }
        
        return d;
    }
};