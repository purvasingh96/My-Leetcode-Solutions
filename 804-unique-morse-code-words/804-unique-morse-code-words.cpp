class Solution {
public:
    int uniqueMorseRepresentations(vector<string>& words) {
        vector<string> m = {".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."};
        
        set<string> st;
        
        for(auto word:words){
            string s = "";
            for(auto c:word){
                s+=m[c-'a'];
            }
            st.insert(s);
        }
        
        return st.size();
        
    }
};