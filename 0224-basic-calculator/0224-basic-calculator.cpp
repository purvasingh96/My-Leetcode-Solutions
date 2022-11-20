class Solution {
private:
    int parseNum(string& s, int& i){
        int len = s.length();
        int temp=0;
        
        for(;i<s.length() && isdigit(s[i]);i++){
            temp = (temp*10 + (s[i]-'0'));
        }
        
        return temp;
    }
    
    int parseExp(string& s, int& i){
        int n = s.length();
        stack<int> st;
        char op = '+';
        
        
        for(;i<s.length() && op!=')';i++){
            
                if(s[i] == ' ') continue;
                int num = s[i] == '(' ? parseExp(s, ++i) : parseNum(s, i);
                
                if(op == '+') {st.push(num);}
                else if(op == '-') st.push(-num);
                
                op = s[i];
            
        }
        
        int res=0;
        
        while(st.size()!=0){
            res+=st.top();
            st.pop();
        }
        cout<<"res: "<<res<<"\n";
        return res;
    }
    
    
public:
    int calculate(string s) {
        int i=0;
        return parseExp(s, i);
    }
};