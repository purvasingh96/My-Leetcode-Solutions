class Solution {
private:
    bool isPal(int start, int end, string& s){
        while(end >=0 && start<s.length() && start<end){
            if(s[start] == s[end]){
                start+=1;
                end-=1;
            } else return false;
        }
        return true;
    }
    
public:
    bool validPalindrome(string s) {
        int start=0, end=s.length()-1;
        while(start<end){
            if(s[start] == s[end]){
                start+=1;
                end-=1;
            } else {
                return isPal(start, end-1, s) || isPal(start+1, end, s);
            }
        }
        return true;
    }
};