class Solution {
public:
    bool canPermutePalindrome(string s) {
        map<char, int> m;
        for(auto c:s) m[c] +=1;
        
        int count=0;
        
        for(auto it:m) {
            count += (it.second)%2;
        }
        
        return count<=1;
    }
};