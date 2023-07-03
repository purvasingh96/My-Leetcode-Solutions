class Solution {
public:
    bool buddyStrings(string s, string t) {
        if(s.length() < 2) return false;
        if(s.length()!=t.length()) return false;
        
        int pos1=-1, pos2=-1;
        int c=0;
        bool greaterThanTwo=false;
        unordered_map<char, int> m;
        
        for(int i=0;i<s.length();i++){
            if(s[i]!=t[i]){
                c+=1;
                if(c>2) return false;
                if(pos1==-1) pos1=i;
                else pos2=i;
            }
            m[s[i]]+=1;
            if(m[s[i]] >=2 ) greaterThanTwo = true;
        }
        
        if(pos1 == -1 && pos2==-1){
            char c = s[0];
            int n = s.length();
            string k(n, c);
            return k==s || greaterThanTwo;
            
        } else if(pos1==-1 || pos2==-1) return false;
        
        char temp = s[pos1];
        s[pos1] = s[pos2];
        s[pos2] = temp;
        
        return s == t;
    
    }
};