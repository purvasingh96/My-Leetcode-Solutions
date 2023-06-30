class Solution {
public:
    int lengthOfLastWord(string s) {
        stringstream ss(s);
        string word;
        string last="";
        
        while(ss>>word){
            last = word;    
        }
        
        return last.length();
        
    }
};