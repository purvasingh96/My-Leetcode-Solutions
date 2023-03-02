class Solution {
public:
    bool closeStrings(string word1, string word2) {
        int m = word1.length(), n = word2.length();
        if(m!=n) return false;
        
        
        sort(word1.begin(), word1.end());
        sort(word2.begin(), word2.end());
        
        if(word1 == word2) return true;
        
        vector<int> m1(26,0);
        vector<int> m2(26,0);
        
        for(auto c:word1) m1[c-'a']+=1;
        for(auto c:word2) m2[c-'a']+=1;
        
        // to check for extra chars
        for(int i=0;i<26;i++){
            if(m1[i]==0 && m2[i]!=0) return false;
            if(m1[i]!=0 && m2[i]==0) return false;
        }
        
        // anagrams formed by operation 1
        sort(m1.begin(), m1.end());
        sort(m2.begin(), m2.end());
        
        return m1==m2;
        
    }
};