class Solution {
public:
    int uniqueMorseRepresentations(vector<string>& words) {
        vector<string> m = {".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."};
        
        unordered_map<string, int> n;
        
        for(auto word:words){
            string s = "";
            for(auto c:word){
                s+=m[c-'a'];
            }
            n[s]+=1;
        }
        
        return n.size();
        
    }
};