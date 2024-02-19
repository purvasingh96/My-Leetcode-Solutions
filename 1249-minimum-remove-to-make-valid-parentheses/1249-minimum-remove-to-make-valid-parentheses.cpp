class Solution {
private:
    int eraseInvalidClosingBrackets(string& s){
        int balance=0;
        string res="";
        for(int i=0;i<s.length();i++){
            if(s[i] == ')'){
                balance-=1;
                if(balance < 0){
                    balance+=1;   
                } else {
                    res += s[i];
                }
            } else {
                if(s[i] == '('){
                    balance+=1;
                }
                res += s[i];
            }
        }
        
        s=res;
        
        return balance;
    }
public:
    string minRemoveToMakeValid(string s) {
        int balance = eraseInvalidClosingBrackets(s);
        cout<<"balance:: "<<balance<<"\n";
        cout<<"s:: "<<s<<"\n";
        for(int i=s.length()-1;i>=0;i--){
            if(s[i] == '(') {
                if(balance>0){
                    balance-=1;
                    s.erase(i, 1);
                }
            }
        }
        
        return s;
    }
};