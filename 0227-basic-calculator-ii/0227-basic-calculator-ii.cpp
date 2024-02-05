class Solution {
public:
    int calculate(string s) {
        int curr=0, last=0, res=0;
        char sign='+';
        
        for(int i=0;i<s.length();i++){
            char c = s[i];
            if(isdigit(c)){
                curr = curr*10 + (c-'0');
            }
            if(!isdigit(c) && c!=' ' || i==s.length()-1) {
                if(sign == '+' || sign == '-'){
                    res += last;
                    last = sign == '+' ? curr : -curr;
                }
                else if(sign == '/'){
                    last = last / curr;
                } else if(sign == '*'){
                    last = last * curr;
                }
                sign=c;
                curr=0;
            }
        }
        
        res += last;
        return res;
    }
};