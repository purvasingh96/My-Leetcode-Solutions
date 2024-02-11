class Solution {
private:
    int invalids(string& s){
        stack<char> st;
        for(auto c:s){
            if(c == '(' || c ==')'){
               if(st.empty() || c == '('){
                st.push(c);
                } else if(c == ')'){
                    if(!st.empty() && st.top() == '('){
                        st.pop();
                    } else {
                        st.push(c);
                    }
                } 
            }
            
        }
        
        return st.size();
    }
    
    int countRemoval(string s){
        stack<char> st;
        for(int i=0;i<s.size();i++){
            if(s[i]=='('){
                st.push('(');
            }
            else if(s[i]==')'){
                if(st.size()==0){
                    st.push(')');
                }
                else if(st.top()==')'){
                    st.push(')');
                }
                else if(st.top()=='('){
                    st.pop();
                }
            }
        }
        
        int invalid=st.size(); //minimum removals
        
        return invalid;
    }
    
    void dfs(string s, int invalid, unordered_set<string>& st, unordered_map<string, bool>& visited){
        
        if(invalid == 0){
            if(!invalids(s)){
                st.insert(s);
                return;
            }    
        }
        
        for(int i=0;i<s.length();i++){
            if(s[i] == ')' || s[i] == '('){
                string temp = s.substr(0, i) + s.substr(i+1);
                if(visited[temp] == false){
                    visited[temp]=true;
                    dfs(temp, invalid-1, st, visited);
                } 
            }
           
        }
        
        
    }
public:
    vector<string> removeInvalidParentheses(string s) {
        int invalid = invalids(s);
        unordered_map<string, bool> visited;
        unordered_set<string> st;
        
        dfs(s, invalid, st, visited);
        vector<string> res(st.begin(), st.end());
        return res;
    }
};