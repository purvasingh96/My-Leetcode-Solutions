class Solution {
public:
    bool isPalindrome(string s) {
        int i=0, j=s.length()-1;
        
        while(i<j){
            if(isalnum(s[i]) && isalnum(s[j])){
                char si = tolower(s[i]);
                char sj = tolower(s[j]);
                
                if(si!=sj) {
                    return false;
                } else {
                    i+=1;
                    j-=1;
                }
            } else {
                if(!isalnum(s[i])){
                    i+=1;
                }
                if(!isalnum(s[j])){
                    j-=1;
                }
            }
        }
        
        return true;
    }
};