class Solution {
public:
    bool canPermutePalindrome(string s) {
        map<char, int> m;
        for(auto c:s) m[c] +=1;
        
        int count=0;
        
        for(auto it:m) {
            if(it.second%2==1) {
                if(s.length()%2 == 1) {
                    if(count != 0) return false;
                    else count+=1;
                } else {
                    return false;
                }
            }
        }
        
        return true;
    }
};