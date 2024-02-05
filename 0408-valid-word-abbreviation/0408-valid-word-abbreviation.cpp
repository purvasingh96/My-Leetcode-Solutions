class Solution {
public:
    bool validWordAbbreviation(string word, string abbr) {
        stack<char> st;
        
        for(int i=word.length()-1;i>=0;i--){
            st.push(word[i]);
        }
        
        for(int i=0;i<abbr.length();i++){
            if(st.empty()) return false;
            if(abbr[i] == st.top()){
                st.pop();
            } else {
                if(isdigit(abbr[i])){
                    
                    if(abbr[i]=='0'){
                        // leading zero;
                        return false;
                    } else {
                        int j=i;
                        int digit=0;
                        while(j<abbr.length() && isdigit(abbr[j])){
                            digit = digit*10 + (abbr[j]-'0');
                            j+=1;
                        }
                        if(digit > st.size()){
                            return false;
                        } else {
                            while(digit--){
                                st.pop();
                            }
                            i = j-1;
                        }
                    }
                    
                } else {
                    return false;
                }
            }
        }
        
        return st.empty();
    }
};