class Solution {
public:
    int lengthOfLastWord(string s) {
        string token="";
        string last="";
        s+= " ";
        for(int i=0;i<s.length();i++){
            if(s[i] == ' '){
                token = "";
                continue;
            } else {
                token += s[i];
            }
            last = token;
        }
        
        return last.length();
    }
};