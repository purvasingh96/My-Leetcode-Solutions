class Solution {
private:
    void reverse(string& s, int start, int end){
        int i = start, j = end;
        while(i<j){
            char t = s[i];
            s[i] = s[j];
            s[j] = t;
            i+=1;
            j-=1;
        }
    }

public:
    string reverseWords(string s) {
        string temp="", ans="";
        s+=" ";
        int j=0;
        
        for(int space=0;space<s.length();space++){
            if(s[space] == ' '){
               int start=j, end=space-1;
               reverse(s, start, end);
                j = space+1;
            }
        }
        s.pop_back();
        return s;
    }
};