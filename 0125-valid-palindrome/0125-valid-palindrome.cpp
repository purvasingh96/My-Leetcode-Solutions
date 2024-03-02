class Solution {
public:
    bool isPalindrome(string s) {
        int l=0, r=s.length()-1;
        
        while(l<r){
            if(isalnum(s[l]) && isalnum(s[r])){
                if(tolower(s[l]) != tolower(s[r])){
                    return false;
                } else if(tolower(s[l]) == tolower(s[r])){
                    l+=1;
                    r-=1;
                }
            } else {
                while(l<r && !isalnum(s[l])){
                    l+=1;
                }
                while(r>l && !isalnum(s[r])){
                    r-=1;
                }
            }
        }
        
        return true;
    }
};