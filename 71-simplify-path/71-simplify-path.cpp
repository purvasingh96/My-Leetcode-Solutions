class Solution {
public:
    string simplifyPath(string path) {
        vector<string> stack;
        stringstream p(path);
        
        string temp;
        
        while(getline(p, temp, '/')) {
            
            if(temp == "." || temp =="") continue;
            else if(stack.size()!=0 && temp == "..") stack.pop_back();
            else if(temp!="..") stack.push_back(temp);
            
        }
        
        string res = "";
        
        for(auto c:stack) {
            
            res += ("/" + c);
            
        }
        
        return stack.empty() ? "/":res;
    }
};