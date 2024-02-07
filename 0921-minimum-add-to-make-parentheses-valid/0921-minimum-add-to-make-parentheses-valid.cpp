class Solution {
public:
    int minAddToMakeValid(string s) {
        int balance=0;
        int res=0;
        
        for(auto c:s){
            if(c==')') {
                balance-=1;
                if(balance<0){
                    res+=1;
                    balance+=1;
                }
            } else if(c == '('){
                balance+=1;
            }
        }
        
        res+=balance;
        return res;
    }
};