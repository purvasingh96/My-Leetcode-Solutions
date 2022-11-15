class Solution {
public:
    bool isPalindrome(int x) {
        if(x<0) return false;
        string t = to_string(x);
        int l=0, r=t.length()-1;
        while(l<r){
            if(t[l++]!=t[r--]) return false;
        }
        return true;
    }
};