class Solution {
private:
public:
    int minInsertions(string s) {
        int balance = 0;
        stack<char> st;
        int ans=0;
        
        for(int i=0;i<s.length();i++){
            if(s[i] == '('){
                st.push(s[i]);
            } else {
                if(st.empty()){
                    if(i+1 < s.length()){
                        if(s.substr(i, 2) == "))"){
                            balance+=1;
                            i+=1;
                        } else {
                            balance+=2;
                        }
                    } else {
                        balance+=2;
                    }
                    //cout<<"balance: "<<balance<<" i: "<<i<<"\n";
                } 
                
                
                
                
                
                else {
                    if(i+1<s.length()){
                        st.pop();
                        if(s.substr(i, 2) == "))"){
                            i+=1;
                        } else {
                            balance+=1;
                        }
                    } else {
                        st.pop();
                        balance+=1;
                    }
                }
            }
        }
        
        return balance + st.size()*2;
        
    }
};