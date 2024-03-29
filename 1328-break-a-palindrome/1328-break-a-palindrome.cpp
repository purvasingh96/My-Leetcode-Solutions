class Solution {
private:
    bool checkPal(string s){
        int n = s.length();
        int l=0, r = n-1;
        while(l<r){
            if(s[l++]!=s[r--]) return false;
        }
        
        return true;
    }
    
public:
    string breakPalindrome(string s) {
        if(s.length()==1) return "";
        
        if(s[0]!='a') {
            s[0]='a';
            return s;
        }
        
        int i=0;
        for(i;i<s.length()/2;i++){
            if(s[i]!='a'){
                string temp = s;
                temp[i] = 'a';
                return temp;
            }
        }
        
        
            s[s.length()-1] = 'b';
        
        
        return s;
    }
};