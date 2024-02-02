class Solution {
public:
    string minRemoveToMakeValid(string s) {
        int open=0, balance =0;
        string res="";
        for(auto c:s) {
            if(c == '('){
                open+=1;
                balance+=1;
            } else if(c == ')'){
                if(balance ==0) continue;
                balance-=1;
            }
            res+=c;
        }
        
        string ans="";
        int openToKeep = open - balance;
        for(int i=0;i<res.length();i++){
            if(res[i] == '('){
                openToKeep -=1;
                if(openToKeep<0) continue;
            }
            ans +=res[i];
        }
        
        return ans;
    }
};