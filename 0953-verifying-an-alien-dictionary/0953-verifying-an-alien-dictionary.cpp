class Solution {
private:
    bool isSorted(string word1, string word2, vector<int>& m){
        
        for(int i=0;i<min(word1.length(), word2.length());i++){
            if(m[word1[i]-'a'] > m[word2[i]-'a']){
                return false;
            } else if(m[word1[i]-'a'] < m[word2[i]-'a']){
                return true;
            }
        }
        return word1.length() <= word2.length();
    }
public:
    bool isAlienSorted(vector<string>& words, string order) {
        vector<int> m(26, 0);
        for(int i=0;i<order.length();i++){
            m[order[i]-'a'] = i;
        }
        
        for(int i=0;i<words.size()-1;i++){
            if(!isSorted(words[i], words[i+1], m)){
                return false;
            }
        }
        
        return true;
    }
};