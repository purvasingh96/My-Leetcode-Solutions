class Solution {
public:
    bool isAnagram(string s, string t) {
        vector<int> original(26, 0);
        vector<int> anagram(26, 0);
        for(auto x:s) original[x-'a']+=1;
        for(auto x:t) anagram[x-'a']+=1;
        return original == anagram;
    }
};