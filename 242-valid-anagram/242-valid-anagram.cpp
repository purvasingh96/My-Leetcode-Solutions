class Solution {
public:
    bool isAnagram(string s, string t) {
        map<char, int> m1;
        
        for(auto c:s) m1[c] += 1;
        for(auto c:t) m1[c] -= 1;
        
        for(auto it:m1) if(it.second) return false;
        return true;
    }
};