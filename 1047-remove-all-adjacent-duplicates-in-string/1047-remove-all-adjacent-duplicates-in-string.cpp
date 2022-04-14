class Solution {
public:
    string removeDuplicates(string s) {
        string t = "";
        for(auto c:s) {
            if(t.length() == 0 || (t.length()>0 && t[t.length()-1]!=c)) {
                t += c;
            } else {
                t.pop_back();
            }
        }
        
        return t;
    }
};