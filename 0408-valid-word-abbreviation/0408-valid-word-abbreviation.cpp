class Solution {
private:
    bool isDigit(char c){
        return c>='0' && c<='9';
    }
public:
    bool validWordAbbreviation(string word, string abbr) {
        stack<char> st;
        for(int i=word.length()-1;i>=0;i--){
            st.push(word[i]);
        }
        
        for(int j=0;j<abbr.length();j++){
            if(st.empty() && j<abbr.length()){
                return false;
            }
            if(st.top() == abbr[j]){
                st.pop();
            }
            else {
                if(isDigit(abbr[j])){
                    // leading zero;
                    if(abbr[j] == '0'){
                        return false;
                    }
                    int len=0;
                    while(j<abbr.length() && isDigit(abbr[j])){
                        len = len*10 + (abbr[j]-'0');
                        j+=1;
                    }
                    j-=1;
                    if(len > st.size()) return false;
                    while(len--){
                        st.pop();
                    }
                    
                } else {
                    return false;
                }
            }
        }
        return st.empty();
    }
};