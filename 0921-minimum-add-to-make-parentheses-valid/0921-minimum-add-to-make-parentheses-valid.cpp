class Solution {
public:
    int minAddToMakeValid(string s) {
        int b=0, c=0;
        for(int i=0;i<s.length();i++){
            if(s[i] == '('){
                b+=1;
            } else if(s[i] == ')'){
                b-=1;
                if(b<0){
                    c+=1;
                    b+=1;
                }
            }
        }
        
        return c + b;
    }
};