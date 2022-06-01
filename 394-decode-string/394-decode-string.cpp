class Solution {
public:
    string decodeString(string s) {
        stack<string> stringStack;
        stack<int> intStack;
        string curr;
        int k=0;
        
        for(auto c:s){
            
            if(isdigit(c)){
                
                k = k*10 + (c-'0');
                
            } else if(c == '['){
                
                intStack.push(k);
                stringStack.push(curr);
                
                curr="";
                k=0;
                
            } else if(c == ']'){
                
                string decoded = stringStack.top();
                stringStack.pop();
                
                for(int j=intStack.top();j>0;j--){
                    decoded += curr;
                }
                intStack.pop();
                curr =decoded;
                
            } else {
                
                curr += c;
            }
            
        }
        
        return curr;
    }
};