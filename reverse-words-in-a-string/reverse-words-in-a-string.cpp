class Solution {
public:
    string reverseWords(string s) {
        int n = s.length();
        reverse(s.begin(), s.end());
        int count=0;
        int idx=0;
        
        for(int start=0;start<n;start++) {
            if(s[start]!=' '){
                
                if(idx!=0) s[idx++] = ' ';
                
                int end = start;
                
                while(end < n && s[end]!=' '){
                    s[idx++] = s[end++];
                }
                
                reverse(s.begin()+idx - (end-start), s.begin()+idx);
                
                start=end;
                
            } 
        }
        
        s.erase(s.begin()+idx, s.end());
        return s;
    }
};