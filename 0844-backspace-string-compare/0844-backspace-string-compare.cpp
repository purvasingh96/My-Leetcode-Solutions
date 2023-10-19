class Solution {
private:
    vector<char> returnStack(string s){
        vector<char> st;
        for(auto c:s){
            if(c!='#') {
                st.push_back(c);
            } else {
                if(!st.empty()){
                    st.pop_back();    
                }
                
            }
        }
        return st;
    }
    
public:
    bool backspaceCompare(string s, string t) {
        if(s==t) return true;
        return returnStack(s) == returnStack(t);
    }
};