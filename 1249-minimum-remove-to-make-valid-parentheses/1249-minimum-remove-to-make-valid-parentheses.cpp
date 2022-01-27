class Solution {
public:
    string balanceString(string s, char open, char close) {
        int balance=0;
        string ans="";
        
        for(int i=0;i<s.length();i++) {
            if(s[i] == open) {
                balance+=1;
            } 
            
            if(s[i] == close) {
                if(balance == 0) continue;
                balance -= 1;
            }
            
            ans += s[i];
        }
        
        return ans;
    }
    
    
    string minRemoveToMakeValid(string s) {
        
        string res = balanceString(s, '(', ')');
        reverse(res.begin(), res.end());
        res = balanceString(res, ')', '(');
        reverse(res.begin(), res.end());
        return res;
        
    }
};