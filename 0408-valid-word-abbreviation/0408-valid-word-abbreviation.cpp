class Solution {
public:
    bool validWordAbbreviation(string word, string abbr) {
        stack<char> st;
        for(int i=word.length()-1;i>=0;i--){
            st.push(word[i]);
        }
        
        for(int i=0;i<abbr.length();i++){
            if(isalpha(abbr[i])){
                if(st.empty()) {
                    return false;
                }
                if(abbr[i] != st.top()){
                    return false;
                } else {
                    st.pop();
                }
            } else {
                int d =0;
                if(abbr[i] == '0'){
                    // leading zero;
                    return false;
                }
                while(i<abbr.length() && isdigit(abbr[i])){
                    d = d*10 + (abbr[i] - '0');
                    i+=1;
                }
                cout<<"d: "<<d<<"\n";
                    
                i-=1;
                while(d){
                    if(st.empty()){
                        return false;
                    }
                    st.pop();
                    d-=1;
                }
                //cout<<"st.top(): "<<st.top()<<" i: "<<i<<"\n";
            }
        }
        
        return st.empty();
    }
};