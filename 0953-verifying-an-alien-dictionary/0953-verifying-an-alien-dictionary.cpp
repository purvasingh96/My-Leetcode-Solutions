class Solution {
private:
    bool isSorted(string word1, string word2, unordered_map<char, int>& m){
        
        for(int i=0;i<min(word1.length(), word2.length());i++){
            if(m[word1[i]] > m[word2[i]]){
                return false;
            } else if(m[word1[i]] < m[word2[i]]){
                return true;
            }
        }
        return word1.length() <= word2.length();
    }
public:
    bool isAlienSorted(vector<string>& words, string order) {
        unordered_map<char, int> m;
        for(int i=0;i<order.length();i++){
            m[order[i]] = i;
        }
        
        for(int i=0;i<words.size()-1;i++){
            if(!isSorted(words[i], words[i+1], m)){
                return false;
            }
        }
        
        return true;
    }
};