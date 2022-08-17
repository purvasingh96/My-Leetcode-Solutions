class Solution {
public:
    int uniqueMorseRepresentations(vector<string>& words) {
        vector<string> m = {".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."};
        
        unordered_set<string> n;
        
        for(auto word:words){
            string s = "";
            for(auto c:word){
                s+=m[c-'a'];
            }
            n.insert(s);
        }
        
        return n.size();
        
    }
};