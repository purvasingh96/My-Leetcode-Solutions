class Solution {
private:
    bool isOrdered(string s1, string s2, unordered_map<char, int>& m){
        for(int i=0;i<min(s1.length(), s2.length());i++){
            if(s1[i] != s2[i]){
                return m[s1[i]] < m[s2[i]];
            }
        }
        
        return s1.length() <= s2.length();
    }
public:
    bool isAlienSorted(vector<string>& words, string order) {
        unordered_map<char, int> m;
        for(int i=0;i<order.length();i++){
            m[order[i]]=i;
        }
        for(int i=0;i<words.size()-1;i++){
            if(!isOrdered(words[i], words[i+1], m)){
                return false;
            }
        }
        
        return true;
    }
};